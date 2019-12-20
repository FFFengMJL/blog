package ClientEnd;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws Exception {
        ClientEnd test = new ClientEnd();
//        test.signIn("mijialong", "123456", new CallBackFunc() {
//            @Override
//            public void done(CallBackFunArg callBackFunArg) {
//                System.out.println(callBackFunArg.bool);
//            }
//        });
//        test.signUp("mijialong", "123456", "781131011@qq.com", "FFFeng", new CallBackFunc() {
//            @Override
//            public void done(CallBackFunArg callBackFunArg) throws Exception {
//                System.out.println(callBackFunArg.bool);
//                test.signIn("mijialong", "123456", new CallBackFunc() {
//                    @Override
//                    public void done(CallBackFunArg callBackFunArg) {
//                        System.out.println(callBackFunArg.bool);
//                    }
//                });
//            }
//        });
        test.signIn("mijialong", "123456", new CallBackFunc() {
            @Override
            public void done(CallBackFunArg callBackFunArg) throws Exception {
                System.out.println(callBackFunArg.bool);
                test.logOut(new CallBackFunc() {
                    @Override
                    public void done(CallBackFunArg callBackFunArg) throws Exception {
                        System.out.println(callBackFunArg.bool);
                    }
                });
            }
        });

    }
}
