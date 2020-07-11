import { download } from "node-hls-downloader/dist/src/http";
// let hls = require("node-hls-downloader/dist/src/http");
// let download = hls.download;

let filename = prompt("文件名: ");
let url = prompt("url: ");

async function down(filename, url) {
  await download({
    quality: "best",
    concurrency: 10,
    outputFile: filename,
    streamUrl: url,
  });
  console.log("download finished");
}
