import optionalRequire from '../Utils/OptionalRequire.js';
const gd = global.gd;

//TODO: Update to ES6
function Bridge()
{
	this.net = optionalRequire('net');

	this.client = null;
	this.connected = false;
	this._onReceiveCb = null;
}

Bridge.prototype.isSupported = function() {
	return !!this.net;
}

Bridge.prototype.connectTo = function(port) {
	if (!this.net) return;

	var that = this;
	this.client = new this.net.Socket();
	this.client.connect(port, 'localhost', function() {
		that.connected = true;
	});

	var data = "";
	this.client.on('data', function(dataBuffer) {
	    data += dataBuffer;
	    if (!dataBuffer.length || dataBuffer[dataBuffer.length - 1] == 0) {
			that._receive(data);
			data = "";
	    }
	});

	this.client.on('close', function() {
		that.connected = false;
	});
}

Bridge.prototype.send = function(command, serializedObject, scope = "") {
	if (!this.connected) return false;

	var element = new gd.SerializerElement();
	element.addChild("command").setString(command);
	element.addChild("scope").setString(scope);
	element.addChild("payload");
	if (serializedObject) element.setChild("payload", serializedObject);

	var json = gd.Serializer.toJSON(element);
	element.delete();

	this.client.write(json + '\0');

	return true;
}

Bridge.prototype._receive = function(data) {
	console.log("Received data");
	var t0 = performance.now();
	var serializedObject = gd.Serializer.fromJSON(data);
	var t1 = performance.now();
	console.log("Call to gd.Serializer.fromJSON took " + (t1 - t0) + " milliseconds.");
	if (this._onReceiveCb) {
		this._onReceiveCb(
			serializedObject.getChild("command").getValue().getString(),
			serializedObject.getChild("payload"),
			serializedObject.getChild("scope").getValue().getString());
	}
}

Bridge.prototype.onReceive = function(cb) {
	this._onReceiveCb = cb;
}

export default Bridge;
