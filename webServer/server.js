
var express = require('express'); // web server application
var app = express(); // webapp
var http = require('http').Server(app); // connects http library to server
var io = require('socket.io')(http); // connect websocket library to server
var serverPort = 8000;
var serialPort = require('serialport'); // serial library
var readLine = serialPort.parsers.Readline; // read serial data as lines
var Omx = require('node-omxplayer');
var Sound = require('node-arecord');

//---------------------- WEBAPP SERVER SETUP ---------------------------------//
// use express to create the simple webapp
app.use(express.static('public')); // find pages in public directory


// start the server and say what port it is on
http.listen(serverPort, function() {
  console.log('listening on *:%s', serverPort);
});
//----------------------------------------------------------------------------//


//---------------------- SERIAL COMMUNICATION --------------------------------//
// start the serial port connection and read on newlines
const serial = new serialPort('/dev/ttyUSB0', {
 baudRate:9600
});
const parser = new readLine({
  delimiter: '\r\n'
});

let drumHash = {
  a1: './drum-sounds/drum1-a.wav',
  b1: './drum-sounds/drum1-b.wav',
  c1: './drum-sounds/drum1-c.wav',
  a2: './drum-sounds/drum2-a.wav',
  b2: './drum-sounds/drum2-b.wav',
  c2: './drum-sounds/drum2-c.wav',
  a3: './drum-sounds/drum3-a.wav',
  b3: './drum-sounds/drum3-b.wav',
  c3: './drum-sounds/drum3-c.wav',

}

let thereminHash = {
  a: './thermin-sounds/thermin-a.wav',
  b: './thermin-sounds/thermin-b.wav',
  c: './thermin-sounds/thermin-c.wav',
}

let flexHash = {
  a: './flex-sounds/flex1.wav',
  b: './flex-sounds/flex2.wav',
}


//drum variables
let drum1 = drumHash['a1'];
let drum2 = drumHash['a2'];
let drum3 = drumHash['a3'];
let thereminLow = thereminHash['a'];
let thereminMid = thereminHash['b'];
let thereminHigh = thereminHash['c'];
let flex = flexHash['a'];

let drum1Player;
let drum2Player;
let drum3Player;
let thereminLowPlayer;
let thereminMidPlayer;
let thereminHighPlayer;
let flexPlayer;
let songPlayer;

var sound = new Sound({
 debug: true,    // Show stdout
 destination_folder: '/recordings',
 filename: 'recording.wav',
 alsa_format: 'dat',
 alsa_device: 'hw:1,0'
});

// // Read data that is available on the serial port and send it to the websocket
serial.pipe(parser);
parser.on('data', data => { // on data from the arduino
  if (data == 'drum1') {
    console.log('drum1')
    // io.emit('drum1');
    // if (songPlayer && songPlayer.running) {
    // if (drum1Player && drum1Player.running) {
    //   drum1Player.quit();
    //   // songPlayer.quit();
    // } else {
      // sound.record();
      // setTimeout(function () {
      //     sound.stop(); // stop after ten seconds
      //     songPlayer = Omx('./recordings/recording.wav');
      // }, 3000);
      // drum1Player = Omx('./songs/song1.mp3');
      drum1Player = Omx(drum1);
    // }
  }
  if (data == 'drum2') {
    console.log('drum2')
    // io.emit('drum1');
    // if (drum2Player && drum2Player.running) {
    //   drum2Player.quit();
    // } else {
      drum2Player = Omx(drum2);
    // }
  }
  if (data == 'drum3') {
    // io.emit('drum1');
    console.log('drum3')
    drum3Player = Omx(drum3);
  }
  if (data == 'thereminLow') {
    // io.emit('drum1');
    console.log('thereminLow')
    thereminLowPlayer = Omx(thereminLow);
  }
  if (data == 'thereminMid') {
    // io.emit('drum1');
    console.log('thereminMid')
    thereminMidPlayer = Omx(thereminMid);
  }
  if (data == 'thereminHigh') {
    // io.emit('drum1');
    console.log('thereminHigh')
    thereminHighPlayer = Omx(thereminHigh);
  }
  if (data == 'flex') {
    console.log('flex')
    // io.emit('drum1');
    if (flexPlayer && flexPlayer.running) {
      flexPlayer.quit();
    } else {
      flexPlayer = Omx(flex);
    }
  }
});
//----------------------------------------------------------------------------//


//---------------------- WEBSOCKET COMMUNICATION -----------------------------//
// this is the websocket event handler and say if someone connects
// as long as someone is connected, listen for messages
io.on('connect', socket => {
  console.log('a user connected');
  io.emit('reset'); // call reset to make sure the website is clean

// if you get the 'disconnect' message, say the user disconnected
  io.on('disconnect', () => {
    console.log('user disconnected');
  });

  socket.on('disconnect', () => { // This function  gets called when the browser window gets closed
    console.log('user disconnected');
  });

  socket.on('thereminLowChange', val => {
    thereminLow = thereminHash[val];
    var player = Omx(thereminLow);
  });
  socket.on('thereminMidChange', val => {
    thereminMid = thereminHash[val];
    var player = Omx(thereminMid);
  });
  socket.on('thereminHighChange', val => {
    thereminHigh = thereminHash[val];
    var player = Omx(thereminHigh);
  });
  socket.on('drum1Change', val => drum1 = drumHash[val]);
  socket.on('drum2Change', val => {
    drum2 = drumHash[val];
    var player = Omx(drum2);
  });
  socket.on('drum3Change', val => {
    drum3 = drumHash[val];
    var player = Omx(drum3);
  });
  socket.on('flexChange', val => {
    flex = flexHash[val];
  });

});
