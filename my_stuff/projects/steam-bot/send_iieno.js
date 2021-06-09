const SteamUser = require('steam-user'); // Replace this with `require('steam-user');` if used outside of the module directory
const SteamID = require('steamid');
var client = new SteamUser();

var username = "usedtoilet666";
var password = "Chenxi202";

client.logOn({
    "accountName": username,
    "password": password
});
var iieno = new SteamID("[U:1:1080833819]");
client.on('loggedOn', function (_details) {
    console.log("[LOGIN] Logged in as " + client.steamID.getSteam3RenderedID());
    var message = "";
    for (var j = Math.floor(Math.random() * 100); j >= 0; j--) {
        message += Math.floor(Math.random() * 10).toString();
    }
    setTimeout(function () {
        client.chatMessage(iieno, message);
        console.log("[MSG] " + message);
    }, 500);
    setTimeout(function () {
        process.exit()
    }, 600);
});