const fs = require('fs')
const cmd = require('node-cmd')
const exec = require('child_process').exec;
const sync = require('child_process').execSync;
const pwd = __dirname
const sys = require('util')
const flags = require('node-flags')
function puts(error, stdout, stderr) { console.log(stdout); }
//
// const argv = process.argv
// const env = argv[2]
// const log = argv[3]
//
// if (env == 'dev'){
//   if(log == 'log') exec("./scripts/dev", puts)
//   else if (log == 'nolog') exec("./scripts/devd", puts)
// }

var env = flags.get('env')
var watch = flags.get('watch')

// if (!env || env == 'dev') sync("./scripts/devd", puts)
if (!env || env == 'dev') cmd.get("./scripts/dev", (data, err, stderr) =>{
  console.log(data);
})
//if (watch) console.log('watching');

console.log("Serving is running on http://localhost:3000");

// exec("./scripts/dev", puts)
