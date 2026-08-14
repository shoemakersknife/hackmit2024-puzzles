const puppeteer = require("puppeteer");
const fs = require('fs');
const myConsole = new console.Console(fs.createWriteStream('./hexscores.txt'));

(async () => {
    let browser;
    try {
        browser = await puppeteer.launch({ headless: false });

        const page = await browser.newPage();

        const lengthOfString = 19;
        const allowedCharacters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'];

        function delay(time) {
            return new Promise(function(resolve) { 
                setTimeout(resolve, time);
            });
        }

        function generateRandomString(length) {
            let result = '';
            for (let i = 0; i < length; i++) {
                const randomIndex = Math.floor(Math.random() * allowedCharacters.length);
                result += allowedCharacters[randomIndex];
            }
            return result;
        }

        async function performActionsWithRandomString(randomString) {
            await page.goto("https://hexhunt.hackmit.org/u/"); // insert username
            await delay(1000);
            await page.mouse.click(270, 100);
            await page.keyboard.type(randomString);
            await delay(1000);
            await page.mouse.click(440, 592);
            const xp = '::-p-xpath(//*[@id="root"]/div/div/div/div[3]/div[2]/p[2]/text()[2])';
            const el = await page.waitForSelector(xp);
            const xpText = await el.evaluate(el => el.textContent);
            console.log(xpText, randomString);
            myConsole.log(xpText, randomString);
            await delay(1000);
        }

        async function typeRandomStrings() {
            while (true) { // Infinite loop until stopped manually
                const randomString = generateRandomString(lengthOfString);
                await performActionsWithRandomString(randomString);
            }
        }

        await typeRandomStrings();

    } catch (err) {
        console.error("Error occurred:", err);
    } finally {
        if (browser) {
            await browser.close();
        }
    }
})();
