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
var message = 33 - 3; // ascii 33 is the first visible character
function send_iieno(i = 0) {
    message += 3;
    if (i === 15) process.exit();
    client.chatMessage(iieno, message.toString() + ' ' + String.fromCharCode(message));
    console.log("[MSG] sent " + message.toString() + " to iieno");
    if (i % 3 === 0) {
        setTimeout(
            function () {
                send_iieno(i + 1);
            },
            3000
        );
    } else {
        setTimeout(
            function () {
                send_iieno(i + 1);
            },
            1000
        );
    }
}
client.on('loggedOn', function (_details) {
    console.log("[LOGIN] Logged in as " + client.steamID.getSteam3RenderedID());
    client.setPersona(SteamUser.EPersonaState.Online);
    send_iieno();
});