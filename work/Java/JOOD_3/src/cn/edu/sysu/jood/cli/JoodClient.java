package cn.edu.sysu.jood.cli;

import cn.edu.sysu.jood.*;
import cn.edu.sysu.jood.core.*;

public class JoodClient implements Client {
    public Jood core;
    public Jood Core() {
        return null;
    }

    public void Init(Configuration cfg) throws InitException {
        this.core = new Jood();
    }

    public void Run() {
		
	}
}