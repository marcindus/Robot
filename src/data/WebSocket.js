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
    connection.send('FORWARD');
};


function backward()
{
    console.log('Backward');
    connection.send('BACKWARD');
};


function left()
{
    console.log('Left');
    connection.send('LEFT');
};


function backward()
{
    connection.send('BACKWARD');
};


