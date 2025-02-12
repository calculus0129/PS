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

class WorkDay {
    constructor(year, month, day) {
        this.year = year;
        this.month = month;
        this.day = day;
    }
    days() {
        return this.year * 360 + this.month * 30 + this.day;
    }
    static dist(start, end) {
        return end.days() - start.days();
    }
};

ps.main(async () => {
  /* main logic goes here */
  let [y, m, d] = (await ps.readArrayLine()).map((t) => parseInt(t));
  const start = new WorkDay(y, m, d);
  [y, m, d] = (await ps.readArrayLine()).map((t) => parseInt(t));
  const end = new WorkDay(y, m, d);
  const days = WorkDay.dist(start, end);
  const months = (days-days%30) / 30;
  const years = (months-months%12)/12;
  const annualLeave = 15*years + (years*(years-1)/2 - (years>>1)>>1);
  const monthlyLeave = Math.min(36, months);
  ps.writeLine(annualLeave + " " + monthlyLeave);
  ps.writeLine(days+"days");
});