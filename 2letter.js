const puppeteer = require("puppeteer");
const fs = require('fs');
const myConsole = new console.Console(fs.createWriteStream('./hexscores.txt'));

(async () => {
    let browser;
    try {
        browser = await puppeteer.launch({ headless: false });

        const page = await browser.newPage();

        const lengthOfString = 19; // Ensure this matches the length of your input string
        const allowedCharacters = ['a', 'c', 'd', 'e', 'g', 'h', 'i', 'j', 'l', 'm', 'n', 'o', 'p', 'r', 's', 't', 'u'];

        function delay(time) {
            return new Promise(resolve => { 
                setTimeout(resolve, time);
            });
        }

        function generateTwoLetterVariations(originalString) {
            const variations = [];
            for (let i = 0; i < originalString.length; i++) {
                for (let j = i + 1; j < originalString.length; j++) {
                    for (const char1 of allowedCharacters) {
                        if (originalString[i] !== char1) {
                            for (const char2 of allowedCharacters) {
                                if (originalString[j] !== char2) {
                                    const newString = originalString.substring(0, i) + char1 + originalString.substring(i + 1, j) + char2 + originalString.substring(j + 1);
                                    variations.push(newString);
                                }
                            }
                        }
                    }
                }
            }
            return variations;
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

            const xpNumber = parseFloat(xpText.replace(/[^0-9.]/g, ''));
            
            // Determine if the number is greater than 2900
            const isGreaterThan2900 = !isNaN(xpNumber) && xpNumber > 3300;
            const starSymbol = isGreaterThan2900 ? '*' : '';

            // Print to console and log to file with optional star symbol
            const output = `${xpNumber} ${randomString} ${starSymbol}`;
            console.log(output);
            myConsole.log(output);

            await delay(1000);
        }

        async function testVariations(originalString) {
            const variations = generateTwoLetterVariations(originalString);
            for (const variation of variations) {
                await performActionsWithRandomString(variation);
            }
        }

        // Replace 'your_input_string' with the actual string you want to test
        const inputString = '';
          await testVariations('dtsreareslpetiosart');
//dtsreareslpetiosart

    } catch (err) {
        console.error("Error occurred:", err);
    } finally {
        if (browser) {
            await browser.close();
        }
    }
})();
