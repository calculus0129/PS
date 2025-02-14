"use strict";

const ps = (function (process) {
  const readline = require("readline");

  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  let lines = [];
  let cursor = 0;

  rl.on("line", function (line) {
    lines.push(line);
  });

  return {
    main(f) {
      f()
        .catch((err) => {
          console.error(err);
          process.exit(1);
        })
        .finally(() => {
          rl.close();
        });
    },
    use(name, f) {
      this[name] = f;
    },
    readLine: async function readLine() {
      return new Promise((resolve) => {
        if (cursor < lines.length) {
          resolve(lines[cursor++]);
        } else {
          setTimeout(() =>
            readLine().then((line) => {
              resolve(line);
            })
          );
        }
      });
    },
    async readArrayLine() {
      const line = await this.readLine();
      return line.split(/\s/);
    },
    write(data) {
      process.stdout.write(data + "");
    },
    writeLine(data) {
      process.stdout.write((data === undefined ? "" : data) + "\n");
    },
    range(start, end, step = 1) {
      if (end === undefined) {
        end = start;
        start = 0;
      }
      return {
        [Symbol.iterator]: function* () {
          for (let i = start; i < end; i += step) {
            yield i;
          }
        },
      };
    },
  };
})(process);

const REPLACEMENT=" *?/+!";

ps.main(async () => {
  let line = (await ps.readLine()).split("");
  while(line != "#") {
    let r = 0;
    let m = new Map();
    for(let i=0;i<line.length;++i) {
        const letter = line[i].toLowerCase();
        if(m.has(letter)) {
            if(m.get(letter) == 0) m.set(letter, ++r);
            line[i] = REPLACEMENT[m.get(letter)];
        } else {
            m.set(letter, 0);
        }
    }
    ps.writeLine(line.join(""));
    line = (await ps.readLine()).split("");
  }
});
