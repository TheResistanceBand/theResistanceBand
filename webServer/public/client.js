var socket = io();        // websocket to the server

socket.on('drum1', function() {
  var audio = new Audio('clap.wav');
  audio.play();
});