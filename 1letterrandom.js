const puppeteer = require("puppeteer");
const fs = require('fs');
const myConsole = new console.Console(fs.createWriteStream('./hexscores.txt'));


(async () => {
    let browser;
    try {
        browser = await puppeteer.launch({
            headless: false
        });

        const page = await browser.newPage();

        const lengthOfString = 19; // Ensure this matches the length of your input string
        const allowedCharacters = ['a', 'c', 'd', 'e', 'g', 'h', 'i', 'l', 'o', 'p', 'r', 's', 't', 'u'];

        function delay(time) {
            return new Promise(resolve => { 
                setTimeout(resolve, time);
            });
        }

        function generateSingleLetterVariations(originalString) {
            const variations = [];
            for (let i = 0; i < originalString.length; i++) {
                for (const char of allowedCharacters) {
                    if (originalString[i] !== char) {
                        const newString = originalString.substring(0, i) + char + originalString.substring(i + 1);
                        variations.push(newString);
                    }
                }
            }
            return variations;
        }

        function shuffleArray(array) {
            for (let i = array.length - 1; i > 0; i--) {
                const j = Math.floor(Math.random() * (i + 1));
                [array[i], array[j]] = [array[j], array[i]]; // Swap elements
            }
        }

        async function performActionsWithRandomString(randomString) {
            await page.goto("https://hexhunt.hackmit.org/u/"); // insert username
            await page.mouse.click(270, 100);
            await delay(1000);
            await page.keyboard.type(randomString);
            await delay(1000);
            await page.mouse.click(440, 592);
            const xp = '::-p-xpath(//*[@id="root"]/div/div/div/div[3]/div[2]/p[2]/text()[2])';
            const el = await page.waitForSelector(xp);
            const xpText = await el.evaluate(el => el.textContent);

            const xpNumber = parseFloat(xpText.replace(/[^0-9.]/g, ''));

            // Determine if the number is greater than 2900
            const isGreaterThan2900 = !isNaN(xpNumber) && xpNumber > 2500;
            const starSymbol = isGreaterThan2900 ? '*' : '';

            // Print to console and log to file with optional star symbol
            const output = `${xpNumber} ${randomString} ${starSymbol}`;
            console.log(output);
            myConsole.log(output);

            await delay(1000);
        }

        async function testVariations(originalString) {
            const variations = generateSingleLetterVariations(originalString);
            shuffleArray(variations); // Shuffle the variations before processing

            for (const variation of variations) {
                await performActionsWithRandomString(variation);
            }
        }

        // Replace 'your_input_string' with the actual string you want to test
        const inputString = 'sinnltrgsatphteiero';

        await testVariations(inputString);

    } catch (err) {
        console.error("Error occurred:", err);
    } finally {
        if (browser) {
            await browser.close();
        }
    }
})();
