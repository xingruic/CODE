const SteamUser = require('steam-user'); // Replace this with `require('steam-user');` if used outside of the module directory
const SteamID = require('steamid');
var client = new SteamUser();

var username = "usedtoilet666";
var password = "Chenxi202";
var message = "message from my steam bot";

client.logOn({
	"accountName": username,
	"password": password
});

var iieno = new SteamID("[U:1:1080833819]");
function send_iieno(i=1){
    if(i>5) return;
    client.chatMessage(iieno, message);
    console.log("sent message to iieno");
    setTimeout(
        function() {
            send_iieno(i+1);
        },
        180000
    );
}

client.on('loggedOn', function(details) {
	console.log("[LOGIN] Logged into Steam as " + client.steamID.getSteam3RenderedID());
	client.setPersona(SteamUser.EPersonaState.Online);
    setTimeout(send_iieno, 180000);// 180000 ms = 30 minutes
    process.exit(1);
});