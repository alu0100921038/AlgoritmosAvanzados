package practica10;


import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.WindowConstants;
import javax.swing.SwingUtilities;

/**
 * Clase principal en la que iniciamos la gui y establecemos los botones y sus funcionalidades
 * @author Juan Martínez Hurtado de Mendoza
 * @since 16-04-2018
 */
public class FPrincipal extends javax.swing.JFrame {
 private PDibujo pDibujo;
 private JPanel PContenedorDibujo;
 private Color color;

/**
 * Clase main en la que iniciamos la gui a traves de un hilo.
 * @param args
 */
 public static void main(String[] args) {
  SwingUtilities.invokeLater(new Runnable() {
   public void run() {
    FPrincipal inst = new FPrincipal();
    inst.setLocationRelativeTo(null);
    inst.setVisible(true);
   }
  });
 }
 
 /**
  * Constructor de la clase. Inicializa la GUI
  */
 public FPrincipal() {
  super();
  initGUI();
 }
 
 /**
  * Se inicializa la GUI, estableciendo los botones y sus funcionalidades.
  */
 
 private void initGUI() {
  try {
   setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
   BorderLayout thisLayout = new BorderLayout();
   getContentPane().setLayout(thisLayout);
   this.setTitle("Random Walk");
   
   JPanel btnPanel = new JPanel(new FlowLayout());
	JButton btnEmpezar = new JButton("Empezar");
	btnPanel.add(btnEmpezar);
	btnEmpezar.addActionListener(new ActionListener() {
       

		@Override
        public void actionPerformed(ActionEvent evt) {
			 	PContenedorDibujo = new JPanel();
			    BorderLayout PContenedorDibujoLayout = new BorderLayout();
			    PContenedorDibujo.setLayout(PContenedorDibujoLayout);
			    getContentPane().add(PContenedorDibujo, BorderLayout.CENTER);
			    pDibujo = new PDibujo(10);
			    PContenedorDibujo.add(pDibujo);
			    pack();
			    setSize(600, 600);
        }
    });
	
	JPanel btnPanel2 = new JPanel(new FlowLayout());
	JButton btnFinalizar = new JButton("Finalizar");
	btnPanel.add(btnFinalizar);
	btnFinalizar.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent evt) {
        	try {
				System.out.println("Terminando el programa en 4 segundos...");
        		Thread.sleep(4000);
				System.exit(0);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
        }
    });
	
	JPanel btnPanel3 = new JPanel(new FlowLayout());
	JButton btnColor = new JButton("Cambiar Color");
	btnPanel.add(btnColor);
	btnColor.addActionListener(new ActionListener() {

		@Override
        public void actionPerformed(ActionEvent evt) {
			Color col = new Color((float) Math.random(), (float) Math.random(), (float) Math.random());
			pDibujo.setColor(col);
		}
    });
	
	JPanel btnPanel4 = new JPanel(new FlowLayout());
	JTextField btnText = new JTextField(10);
	JButton btnEnter = new JButton("Convertir");
	btnPanel.add(btnText);
	btnPanel.add(btnEnter);
	btnEnter.addActionListener(new ActionListener() {

		@Override
        public void actionPerformed(ActionEvent evt) {
			dispose();
        	String texto = btnText.getText();
        	int num = Integer.parseInt(texto);
        	PContenedorDibujo = new JPanel();
            BorderLayout PContenedorDibujoLayout = new BorderLayout();
            PContenedorDibujo.setLayout(PContenedorDibujoLayout);
            getContentPane().add(PContenedorDibujo, BorderLayout.CENTER);
            pDibujo = new PDibujo(num);
            PContenedorDibujo.add(pDibujo);
            pack();
            setSize(600, 600);
            setVisible(true);
            
        }
    });
	
	Container cp = getContentPane();
    cp.setLayout(new BorderLayout());
    cp.add(btnPanel, BorderLayout.SOUTH);
    setSize(600, 600);
    
    
  } catch (Exception e) {
   e.printStackTrace();
  }
 }
}