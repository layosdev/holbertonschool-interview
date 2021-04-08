#!/usr/bin/node
const args = process.argv.slice(2);
const URL = "https://swapi-api.hbtn.io/api/films/" + args[0];
const request = require("request");

let getCharacterName = (link) => {
    const characterName = new Promise((resolve, reject) => {
        request(link, (error, response, body) => {
            if (error) console.error("error:", error);
            resolve(JSON.parse(body).name);
        });
    });
    return characterName;
};

request(URL, async (error, response, body) => {
    if (error) console.error("error:", error);
    let characters = JSON.parse(body).characters;
    for (let i = 0; i < characters.length; i++) {
        let characterName = await getCharacterName(characters[i]);
        console.log(characterName);
    }
});
