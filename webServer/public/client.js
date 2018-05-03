var socket = io();        // websocket to the server

socket.on('drum1', function() {
  var audio = new Audio('clap.wav');
  audio.play();
});

$('#theremin-low').on('change', e => {
	socket.emit('thereminLowChange', e.target.value);
	console.log(e.target.value)
});

$('#theremin-mid').on('change', e => {
	socket.emit('thereminMidChange', e.target.value);
	console.log(e.target.value)
});

$('#theremin-high').on('change', e => {
	socket.emit('thereminHighChange', e.target.value);
	console.log(e.target.value)
});
