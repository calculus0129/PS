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

ps.main(async () => {
  /* main logic goes here */
  const dists = [0, 1];
  for(let i=2;i<=11;++i) {
    dists.push(dists[i-1] + 3*(1<<i-2));
  }
  const [x, y] = (await ps.readArrayLine()).map(t => parseInt(t));
  let cnt = 0, dist = 1;
  if(x > y) ++cnt, ++dist;
  
  while(Math.abs(x-y) > dist) {
    cnt += 2;
    dist <<= 2;
  }
  ps.writeLine(dists[cnt] + Math.abs(x-y) + (cnt>0 ? 1<<cnt-1 : 0));
});

// ps.main(async () => {
//   const [x, y] = (await ps.readArrayLine()).map(t => parseInt(t));
//   let cnt = 0, dist = 0, prevpos = x, pos = x;
//   while((y-x) * Math.sign(y-pos) > 0) {
//     prevpos = pos;
//     pos = x + (cnt&1 ? -1 : 1) * (1<<cnt);
//     ++cnt;
//     dist += Math.abs(pos-prevpos);
//   }
//   dist -= Math.abs(pos-y);
//   ps.writeLine(dist);
// });