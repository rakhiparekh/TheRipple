var app = require('express')(); //i need express library
var http = require('http').Server(app); //making a http server from express app
var io = require('socket.io')(http); 


var serialport = require("serialport"),	// include the serialport library
	SerialPort  = serialport.SerialPort,	// make a local instance of it
	portName = "/dev/tty.usbmodem1411";			// get the serial port name from the command line

var serialport1 = require("serialport"),	// include the serialport library
	SerialPort1  = serialport.SerialPort,	// make a local instance of it
	portName1 = "/dev/tty.usbmodem1421";			// get the serial port name from the command line

//write to json
// var fs = require('fs')
// var outputFilename = '../sensorData/sensorData.json';
// var sensorData = {
// 	sensor0 : '',
// 	sensor1 : '',
// }
// fs.writeFile(outputFilename, JSON.stringify(sensor0, sensor1), function(err) {
//     if(err) {
//       console.log(err);
//     } else {
//       console.log("JSON saved to " + outputFilename);
//     }
// }); 



// open the serial port. The portname comes from the command line:
var myPort = new SerialPort(portName, {
	baudRate: 115200,
	// look for return and newline at the end of each data packet:
	parser: serialport.parsers.readline("\r\n")
});

var myPort1 = new SerialPort(portName1, {
	baudRate: 115200,
	// look for return and newline at the end of each data packet:
	parser: serialport.parsers.readline("\r\n")
});

//listening for the connection event with the client line 20
io.on('connection', function(socket){
  console.log('a user connected');
});

//
http.listen(3000, function(){
  console.log('listening on *:3000');
});

//request a file at the top level
app.get('/', function(req, res){	
  res.sendFile(__dirname + '/wave.html');

});

//making html connection to css
app.get('/wave.css', function(req, res){	
  res.sendFile(__dirname + '/wave.css');
}); 

// called when the serial port opens:
myPort.on('open', function() {
	console.log('port open');
	console.log('baud rate: ' + myPort.options.baudRate);
});


	// called when there's new incoming serial data:
myPort.on('data', function (data) {
	// for debugging, you should see this in Terminal:
	console.log("\n myPort.on data");
	console.log("raw data: "+ data);
	console.log("split by BZero: ", data.split("BZero"));
	if (data.split("BZero")[0] === ""){
		var bpmZero= data.split("BZero")[1];
		io.emit('beatZero',bpmZero);//sending message to client side-speaking from sensor on analog input A0
		console.log(bpmZero+"bpmZero");
	}
});

// called when the serial port closes:
myPort.on('close', function() {
	console.log('port closed');
});

// called when there's an error with the serial port:
myPort.on('error', function(error) {
	console.log('there was an error with the serial port: ' + error);
	myPort.close();
});

myPort1.on('open', function() {
	console.log('port open');
	console.log('baud rate: ' + myPort1.options.baudRate);
});

myPort1.on('data', function (data1) {
	// for debugging, you should see this in Terminal:
	console.log("\n myPort1.on data");
	console.log("raw data: "+ data1);
	console.log("split by BOne: ", data1.split("BOne"));

    if (data1.split("BOne")[0] ===""){
		var bpmOne=data1.split("BOne")[1];
		io.emit('beatOne',bpmOne);//sending message to client side-speaking from sensor on analog input A1
		console.log(bpmOne+"bpmOne");
	}
});

// called when the serial port closes:
myPort1.on('close', function() {
	console.log('port closed');
});

// called when there's an error with the serial port:
myPort1.on('error', function(error) {
	console.log('there was an error with the serial port: ' + error);
	myPort.close();
});




 
