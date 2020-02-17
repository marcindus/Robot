var rainbowEnable = false;
var connection = new WebSocket('ws://'+location.hostname+':81/', ['arduino']);
connection.onopen = function ()
{
    connection.send('Connect ' + new Date());
};
connection.onerror = function (error)
{
    console.log('WebSocket Error ', error);
};
connection.onmessage = function (e)
{
    console.log('Server: ', e.data);
};
connection.onclose = function(){
    console.log('WebSocket connection closed');
};

function forward()
{
    console.log('Forward');
    connection.send('F');
};

function stop()
{
    console.log('Stop');
    connection.send('S');
};


function backward()
{
    console.log('Backward');
    connection.send('B');
};


function left()
{
    console.log('Left');
    connection.send('L');
};

function right()
{
    console.log('Right');
    connection.send('R');
};

function sendCorrection()
{
    var corr = document.getElementById('correction').value;
    var corrstr = '#'+ corr.toString(16);    
    console.log('correction: ' + corrstr); 
    connection.send(corrstr);
};





