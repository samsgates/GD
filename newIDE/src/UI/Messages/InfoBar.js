import React, { Component } from 'react';
import Snackbar from 'material-ui/Snackbar';

export default class ToolbarIcon extends Component {
  constructor() {
    super();
    this.state = {
      dismissed: false,
    }
  }

  handleGotIt = () => {
    localStorage.setItem(`gdevelop.hiddenMessages.${this.props.messageId}`, true);
    this.setState({dismissed: true});
  }

  componentWillReceiveProps(newProps) {
    if (this.props.message !== newProps.message) {
      this.setState({dismissed: false});
    }
  }

  render() {
    const hidden = localStorage.getItem(`gdevelop.hiddenMessages.${this.props.messageId}`);

    return (
      <Snackbar
        open={this.props.show && !hidden && !this.state.dismissed}
        message={this.props.message}
        onRequestClose={() => this.setState({dismissed: true})}
        action="Got it"
        onActionTouchTap={this.handleGotIt}
      />
    );
  }
}
