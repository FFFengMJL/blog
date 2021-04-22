let reg = /(torrent|.torrent|peer_id=|info_hash|get_peers|find_node|BitTorrent|announce_peer|announce.php?passkey=)/;
let qbt =
  "[LoliHouse] Blue Reflection Ray - 01 [WebRip 1080p HEVC-10bit AAC ASSx2].mkv.torrent";
console.log(reg.exec(qbt));
