var app = require('express')(); //i need express library
var http = require('http').Server(app); //making a http server from express app
var io = require('socket.io')(http); 

//request a file at the top level
app.get('/', function(req, res){	
  res.sendFile(__dirname + '/wave.html');

});

//making html connection to css
app.get('/wave.css', function(req, res){	
  res.sendFile(__dirname + '/wave.css');

}); 

//listening for the connection event with the client line 20
io.on('connection', function(socket){
  console.log('a user connected');
});

//
http.listen(3000, function(){
  console.log('listening on *:3000');
});


// johnny-five to arduino

var five = require("johnny-five"),
  board, sensor;

board = new five.Board();

board.on("ready", function() {

  // Create a new `sensor` hardware instance.
  sensor = new five.Sensor({
    pin: "A0",
    freq: 250,
  });

  // Inject the `sensor` hardware into
  // the Repl instance's context;
  // allows direct command line access
  board.repl.inject({
    sensor: sensor
  });

  // Properties

  // sensor.scaled
  //
  // Current value of a sensor, scaled to a value
  // between the lower and upper bound set by calling
  // scale( low, high ).
  //
  // Defaults to value between 0-255
  //


  // Sensor Event API

  // "data"
  //
  // Fires when the pin is read for a value
  //
  sensor.on("data", function() {
    console.log(this.value, this.raw);
    io.emit('pulse',this.value);//sending message to client side-speaking 
  });

  // "change"
  //
  // Aliases: "bend", "force", "slide", "touch"
  //
  // Fires when value of sensor changes
  //
});