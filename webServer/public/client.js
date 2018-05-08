var socket = io();        // websocket to the server

// socket.on('drum1', function() {
//   var audio = new Audio('clap.wav');
//   audio.play();
// });

$('#record-start').on('click', e => {
    socket.emit('record', "start");
    console.log("Recording Started");
});

$('#record-stop').on('click', e => {
    socket.emit('record', "stop");
    console.log("Recording Stopped");
});

$('#record-play').on('click', e => {
    socket.emit('record', "play");
    console.log("Recording Playing");
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

$('#drum1').on('change', e => {
    socket.emit('drum1Change', e.target.value);
    console.log(e.target.value)
});

$('#drum2').on('change', e => {
    socket.emit('drum2Change', e.target.value);
    console.log(e.target.value)
});

$('#drum3').on('change', e => {
    socket.emit('drum3Change', e.target.value);
    console.log(e.target.value)
});

$('#flex').on('change', e => {
    socket.emit('flexChange', e.target.value);
    console.log(e.target.value)
});



$('#song-1').on("click", e => {
  socket.emit('play-song', 1);
  console.log("Playing Song " + 1);
});

$('#song-2').on("click", e => {
  socket.emit('play-song', 2);
  console.log("Playing Song " + 2);
});


$('#song-3').on("click", e => {
  socket.emit('play-song', 3);
  console.log("Playing Song " + 3);
});

$('#song-stop').on("click", e => {
  socket.emit('stop-song');
  console.log("Stopping Song");
});
