import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class RemoteControl extends JFrame {
    private static final long serialVersionUID = 1L;
    private JTextArea textArea;
    private JTextField inputField;
    private RemoteClient client;

    public RemoteControl() {
        setTitle("Multimedia Remote Control");
        setSize(600, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        try {
            client = new RemoteClient("localhost", 3331);
        } catch (Exception e) {
            JOptionPane.showMessageDialog(this, "Failed to connect to server", "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(1);
        }

        textArea = new JTextArea(10, 30);
        textArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(textArea);
        
        inputField = new JTextField(20);
        JButton searchButton = new JButton("Search");
        JButton playButton = new JButton("Play");
        
        searchButton.addActionListener(e -> sendRequest("SEARCH"));
        playButton.addActionListener(e -> sendRequest("PLAY"));

        JPanel inputPanel = new JPanel();
        inputPanel.add(new JLabel("Enter multimedia name: "));
        inputPanel.add(inputField);
        inputPanel.add(searchButton);
        inputPanel.add(playButton);
        
        add(inputPanel, BorderLayout.NORTH);
        add(scrollPane, BorderLayout.CENTER);
        
        setVisible(true);
    }

    private void sendRequest(String command) {
        String input = inputField.getText().trim();
        if (!input.isEmpty()) {
            String response = client.send(command + " " + input);
            textArea.append("\n" + response);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(RemoteControl::new);
    }
} 