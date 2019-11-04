package cn.edu.sysu.jood.core;

import java.util.List;

import cn.edu.sysu.jood.core.Chessman.Status;
class LogItem {
    Position from, to;
    Status status;
}

class Logs {
    private List<LogItem> logs;
}
