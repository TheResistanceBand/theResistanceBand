var socket = io();        // websocket to the server

socket.on('drum1', function() {
  var audio = new Audio('clap.wav');
  audio.play();
});

$('#theremin-low').on('change', e => console.log(e.target.value));
$('#theremin-mid').on('change', e => console.log(e.target.value));
$('#theremin-high').on('change', e => console.log(e.target.value));
