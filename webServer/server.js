
var express = require('express'); // web server application
var app = express(); // webapp
var http = require('http').Server(app); // connects http library to server
var io = require('socket.io')(http); // connect websocket library to server
var serverPort = 8000;
var serialPort = require('serialport'); // serial library
var readLine = serialPort.parsers.Readline; // read serial data as lines
var Omx = require('node-omxplayer');

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
// const serial = new serialPort('/dev/ttyUSB0', {
//  baudRate:9600

// });
// const parser = new readLine({
//   delimiter: '\r\n'
// });

//drum variables
let drum1 = 'clap.wav';
let drum2 = 'clap.wav';
let drum3 = 'clap.wav';
let thereminLow = 'clap.wav';
let thereminMid = 'clap.wav';
let thereminHigh = 'clap.wav';
let flex = 'clap.wav';


// // Read data that is available on the serial port and send it to the websocket
// serial.pipe(parser);
// parser.on('data', data => { // on data from the arduino
//   if (data == 'drum1') {
//     // io.emit('drum1');
//     var player = Omx(drum1);
//   }
//   if (data == 'drum2') {
//     // io.emit('drum1');
//     var player = Omx(drum2);
//   }
//   if (data == 'drum3') {
//     // io.emit('drum1');
//     var player = Omx(drum3);
//   }
//   if (data == 'thereminLow') {
//     // io.emit('drum1');
//     var player = Omx(thereminLow);
//   }
//   if (data == 'thereminMid') {
//     // io.emit('drum1');
//     var player = Omx(thereminMid);
//   }
//   if (data == 'thereminHigh') {
//     // io.emit('drum1');
//     var player = Omx(thereminHigh);
//   }
//   if (data == 'flex') {
//     // io.emit('drum1');
//     var player = Omx(flex);
//   }
// });
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

  socket.on('thereminLowChange', val => thereminLow = val);
  socket.on('thereminMidChange', val => thereminMid = val);
  socket.on('thereminHighChange', val => thereminHigh = val);
  socket.on('drum1Change', val => drum1 = val);
  socket.on('drum2Change', val => drum2 = val);
  socket.on('drum3Change', val => drum3 = val);
  socket.on('flexChange', val => flex = val);
