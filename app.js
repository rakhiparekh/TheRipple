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

//johnny-five to board arduino

var five = require("johnny-five"),
  board, button;

board = new five.Board();
console.log("app is ready")

board.on("ready", function() {
	console.log("board ready");

  // Create a new `button` hardware instance.
  // This example allows the button module to
  // create a completely default instance
  button = new five.Button(4);// arduino pin

  // Inject the `button` hardware into
  // the Repl instance's context;
  // allows direct command line access
  board.repl.inject({
    button: button
  });

  // Button Event API

  // "down" the button is pressed
  button.on("down", function() {
    console.log("down");
    io.emit('test',300);//sending message to client side-speaking 
    
  });

  // "hold" the button is pressed for specified time.
  //        defaults to 500ms (1/2 second)
  //        set
  button.on("hold", function() {
    console.log("hold");
  });

  // "up" the button is released
  button.on("up", function() {
    console.log("up");
    
  });
});