const SteamUser = require('steam-user'); // Replace this with `require('steam-user');` if used outside of the module directory
const SteamID = require('steamid');
var client = new SteamUser();

var username = "usedtoilet666";
var password = "Chenxi202";
var message = ".";

client.logOn({
	"accountName": username,
	"password": password
});

var iieno = new SteamID("[U:1:1080833819]");
function send_iieno(i=1){
    if(i>50) process.exit();
    client.chatMessage(iieno, message);
    console.log("[MSG] sent message to iieno");
    setTimeout(
        function() {
            send_iieno(i+1);
        },
        50
    );
}

client.on('loggedOn', function(details) {
	console.log("[LOGIN] Logged into Steam as " + client.steamID.getSteam3RenderedID());
	client.setPersona(SteamUser.EPersonaState.Online);
    setTimeout(send_iieno, 50);// 180000 ms = 30 seconds
});