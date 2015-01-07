var app = require('express')(); //i need express library
var http = require('http').Server(app); //making a http server from express app
var io = require('socket.io')(http); 


var serialport = require("serialport"),	// include the serialport library
	SerialPort  = serialport.SerialPort,	// make a local instance of it
	portName = "/dev/tty.usbmodem1421";			// get the serial port name from the command line

// open the serial port. The portname comes from the command line:
var myPort = new SerialPort(portName, {
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
	console.log(""+ data);
	if (data.split("BZero")[0] === ""){
		var bpmZero= data.split("BZero")[1];
		io.emit('beatZero',bpmZero);//sending message to client side-speaking from sensor on analog input A0
		
		console.log(bpmZero+"bpmZero");
}else if
	(data.split("BOne")[0] ===""){
		var bpmOne=data.split("BOne")[1];
		io.emit('beatOne',bpmOne);//sending message to client side-speaking from sensor on analog input A1
		console.log(bpmOne+"bpmOne");
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



 
