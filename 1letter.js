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
        //const allowedCharacters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'r', 's', 't', 'u', 'v', 'w'];
        const allowedCharacters = ['a', 'c', 'd', 'e', 'g', 'h', 'i', 'l', 'm', 'n', 'o', 'p', 'r', 's', 't', 'u', 'v'];

        function delay(time) {
            return new Promise(resolve => { 
                setTimeout(resolve, time);
            });
        }

        function generateOneLetterVariations(originalString) {
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
            const isGreaterThan2900 = !isNaN(xpNumber) && xpNumber > 2000;
            const starSymbol = isGreaterThan2900 ? '*' : '';

            // Print to console and log to file with optional star symbol
            const output = `${xpNumber} ${randomString} ${starSymbol}`;
            console.log(output);
            myConsole.log(output);
            await delay(1000);
            page.deleteCookie();
        }

        async function testVariations(originalString) {
            const variations = generateOneLetterVariations(originalString);
            for (const variation of variations) {
                await performActionsWithRandomString(variation);
            }
        }

        // Replace 'your_input_string' with the actual string you want to test
        const inputString = '';
          await testVariations('stdreartslpeeoisart');  // best string found
    
  /* stsrearedlpetiosart
  stsrearedlpeviosart
      ranotigesatenierams
       */

    } catch (err) {
        console.error("Error occurred:", err);
    } finally {
        if (browser) {
            await browser.close();
        }
    }
})();
