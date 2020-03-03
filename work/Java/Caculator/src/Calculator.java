import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.util.Stack;

@SuppressWarnings("serial")
public class Calculator extends JFrame {
    private JTextField textField;

    private void init() {
        textField = new JTextField();
        textField.setEditable(false);
        textField.setHorizontalAlignment (JTextField.RIGHT);
        textField.setFont(new Font(null, Font.PLAIN, 20));


        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(4, 4));

        Container container = getContentPane();
        container.add(textField, BorderLayout.NORTH);
        container.add(panel, BorderLayout.CENTER);

        panel.add(createButton("7"));
        panel.add(createButton("8"));
        panel.add(createButton("9"));
        panel.add(createButton("/"));


        panel.add(createButton("4"));
        panel.add(createButton("5"));
        panel.add(createButton("6"));
        panel.add(createButton("*"));

        panel.add(createButton("1"));
        panel.add(createButton("2"));
        panel.add(createButton("3"));
        panel.add(createButton("-"));


        panel.add(createButton("0"));
        panel.add(createButton("C"));
        panel.add(createButton("="));
        panel.add(createButton("+"));
    }

    public JButton createButton (String key) {
        // 创建按钮
        JButton button = new JButton(key);
        button.setFont(new Font("粗体", Font.PLAIN, 15));

        // 单击时触发
        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent event) {
                // 获取目标按钮
                JButton sourceBtn = (JButton) event.getSource();
                // 获取按钮上的字符
                String bottonKey = sourceBtn.getText();
                // 执行字符对应的操作
                calculatorAction(bottonKey);
            }
        });

        return button;
    }

    private Boolean isNum(char key) {
        switch (key) {
            case '.': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': return true;
            default: return false;
        }
    }

    private String caculate(String eval) throws IOException {
        if (!isNum(eval.charAt(eval.length() - 1))) return "Error"; // 最后一个字符不是数字时

        String[] storage = eval.split(" ");
        Stack<Double> stack = new Stack<Double>();
        double firstNum = Double.parseDouble(storage[0]);
        stack.push(firstNum);

        for (int i = 1; i < storage.length; i += 2) {
            switch (storage[i]) {
                case "+" : stack.push(Double.parseDouble(storage[i + 1])); break;
                case "-" : stack.push(-Double.parseDouble(storage[i + 1])); break;
                case "*" : {
//                    double frontNum = stack.pop();
                    stack.push(stack.pop() * Double.parseDouble(storage[i + 1]));
                    break;
                }
                case "/" : {
                    Double nextNum = Double.parseDouble(storage[i + 1]);
                    if (nextNum == 0) return "Error";
                    else stack.push(stack.pop() / nextNum);
                    break;
                }
            }
        }

        double ans = 0;
        while (!stack.empty()) ans += stack.pop();

        return  String.valueOf(ans);
    }

    private int findLastSym(String eval) {
        for (int i = eval.length() - 1; i != 0; i--) {
            char test = eval.charAt(i);
            if (test == '*' || test == '+' || test == '-' || test == '/') return i;
        }
        return 0;
    }

    private void calculatorAction(String key) {
        String text = textField.getText();
        switch(key) {
            case "0": case "1": case "2": case "3": case "4": case "5": case "6": case "7": case "8": case "9": {
                if (text.equals("Error")) text = "";
                else if (text.length() == 0);
                else if(!isNum(text.charAt(text.length() - 1))) text = text + ' ';
                textField.setText(text + key);
                break;
            }
            case ".": {
                if (text.length() == 0) text = "0.";
                else if (text.lastIndexOf(".") < findLastSym(text)) textField.setText(text + '.');
                break;
            }
            case "+": case "-": case "*": case "/": {
                if (text.length() == 0 || text.equals("Error")) textField.setText("0 " + key); // 没有输入的情况
                else if (isNum(text.charAt(text.length() - 1)) == false) { // 不是数字的时候
                    text = text.substring(0, text.length() - 1) + key;
                    textField.setText(text);
                }
                else textField.setText(text + " " + key);
                break;
            }
            case "C": textField.setText(""); break;
            case "=" : {
                try{
                    String res = caculate(text);
                    textField.setText(res);
                    break;
                } catch (IOException s) {
                    textField.setText("Error");
                }
            }
            default:
                break;
        }
    }

    public static void main(String[] args) {
        Calculator calculator = new Calculator();

        calculator.setTitle("Calculator");
        calculator.setSize(300, 300);
        calculator.setResizable(false);
        calculator.setLocationRelativeTo(null);
        calculator.setDefaultCloseOperation(EXIT_ON_CLOSE);

        calculator.init();

        // 显示窗口
        calculator.setVisible(true);
    }
}

