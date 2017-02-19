import React, { Component } from 'react';
import FlatButton from 'material-ui/FlatButton';
import TextField from 'material-ui/TextField';
import Dialog from 'material-ui/Dialog';
import Toggle from 'material-ui/Toggle';

export default class SetupGridDialog extends Component {
  constructor(props) {
    super(props);
    this.state = props.options;
  }

  _onApply = () => {
    this.props.onApply({
      gridWidth: this.state.gridWidth,
      gridHeight: this.state.gridHeight,
      gridOffsetX: this.state.gridOffsetX,
      gridOffsetY: this.state.gridOffsetY,
    });
  }

  render() {
    const actions = [
      <FlatButton
        label="Cancel"
        primary={true}
        onTouchTap={this.props.onCancel}
      />,
      <FlatButton
        label="Apply"
        primary={true}
        keyboardFocused={true}
        onTouchTap={this._onApply}
      />,
    ];

    return (
      <Dialog
        actions={actions}
        modal={true}
        open={this.props.open}
        onRequestClose={this.props.onCancel}
        autoScrollBodyContent={true}
      >
        <TextField
          floatingLabelText="Cell width (in pixels)"
          type="number"
          value={this.state.gridWidth}
          onChange={(e, value) => this.setState({gridWidth: parseInt(value, 10)})}
        />
        <TextField
          floatingLabelText="Cell height (in pixels)"
          type="number"
          value={this.state.gridHeight}
          onChange={(e, value) => this.setState({gridHeight: parseInt(value, 10)})}
        />
        <TextField
          floatingLabelText="X offset (in pixels)"
          type="number"
          value={this.state.gridOffsetX}
          onChange={(e, value) => this.setState({gridOffsetX: parseInt(value, 10)})}
        />
        <TextField
          floatingLabelText="Y offset (in pixels)"
          type="number"
          value={this.state.gridOffsetY}
          onChange={(e, value) => this.setState({gridOffsetY: parseInt(value, 10)})}
        />
      </Dialog>
    )
  }
}
