package practica10;

import java.awt.*;       // Using AWT's Graphics and Color
import java.awt.event.*; // Using AWT's event classes and listener interface
import java.util.Random;

import javax.swing.*;    // Using Swing's components and containers

/**
 * Clase MoveABall en la que definimos los botones para mover la bola además de la clase DrawCanvas donde se dibuja la bola
 * @author Juan Martínez Hurtado de Mendoza
 * @since 8-04-2018
 */
public class modificacion extends JFrame {
    // Definimos constantes

    public static final int CANVAS_WIDTH = 700;
    public static final int CANVAS_HEIGHT = 350;
    public static final Color LINE_COLOR = Color.BLACK;
    public static final Color CANVAS_BACKGROUND = Color.GRAY;
    public boolean isPressed = false;
    int [] yVal = new int[1];
	int [] xVal = new int[1];

    // Posicionamos el balor en el centro
    private int x = CANVAS_WIDTH / 2;
    private int y = CANVAS_HEIGHT / 2;


    private DrawCanvas canvas; 
	
    /**
     * Constructor que inicializa los componentes de la GUI y los manejadores de eventos
     * @param pixelsASaltar numero de pixels que deseamos que se mueva la pelota
     */
    public modificacion() {
        // JPanel para los botones 
    	
        JPanel btnPanel = new JPanel(new FlowLayout());
        JButton btnLeft = new JButton("Drop 1 ");
        btnPanel.add(btnLeft, BorderLayout.WEST);
        btnLeft.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent evt) {
            	xVal = new int [1];
            	yVal = new int [1];
                for (int i = 0; i<1; i++){
                    xVal[i] = (int) (Math.random() * 700) + 1;
                }
                for (int i = 0; i<1; i++){
                    yVal[i] = (int) (Math.random() * 700) + 1;
                }
               repaint();
               
            }
        });
        JButton btnRight = new JButton("Drop 10");
        btnPanel.add(btnRight, BorderLayout.EAST);
        btnRight.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent evt) {
            	xVal = new int [10];
            	yVal = new int [10];
            	for (int i = 0; i<10; i++){
                    xVal[i] = (int) (Math.random() * 700) + 1;
                }
                for (int i = 0; i<10; i++){
                    yVal[i] = (int) (Math.random() * 700) + 1;
                }
                repaint();
            }
        });
        JButton btnUp = new JButton("Drop 100");
        btnPanel.add(btnUp, BorderLayout.NORTH);
        btnUp.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent evt) {
            	xVal = new int [100];
            	yVal = new int [100];
            	for (int i = 0; i<100; i++){
                    xVal[i] = (int) (Math.random() * 700) + 1;
                }
                for (int i = 0; i<100; i++){
                    yVal[i] = (int) (Math.random() * 700) + 1;
                }
                repaint();
            }
        });
        JButton btnDown = new JButton("Drop 1000");
        btnPanel.add(btnDown, BorderLayout.SOUTH);
        btnDown.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent evt) {
            	xVal = new int [1000];
            	yVal = new int [1000];
            	for (int i = 0; i<1000; i++){
                    xVal[i] = (int) (Math.random() * 700) + 1;
                }
                for (int i = 0; i<1000; i++){
                    yVal[i] = (int) (Math.random() * 700) + 1;
                }
                repaint();
            }
        });
    	JTextField btnText = new JTextField(10);
    	JButton btnEnter = new JButton("Aceptar");
    	btnPanel.add(btnText);
    	btnPanel.add(btnEnter);
    	btnEnter.addActionListener(new ActionListener() {

    		@Override
            public void actionPerformed(ActionEvent evt) {
                
            }
        });

        // inicializamos nuestro panel para dibujar
        canvas = new DrawCanvas();
        canvas.setPreferredSize(new Dimension(CANVAS_WIDTH, CANVAS_HEIGHT));

        // Añadimos ambos paneles al contentPane
        Container cp = getContentPane();
        cp.setLayout(new BorderLayout());
        cp.add(canvas, BorderLayout.CENTER);
        cp.add(btnPanel, BorderLayout.SOUTH);

        setSize(500, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Manejamos el botón de cerrar
        setTitle("La aguja de Buffon");
        pack();          
        setVisible(true);
        requestFocus(); 
    }

    /**
     * Definimos la clase DrawCanvas que extiende de JPanel y en la que dibujaremos nuestra bola
     */
    class DrawCanvas extends JPanel {

        @Override
        public void paintComponent(Graphics g) {
            super.paintComponent(g);
            int x = CANVAS_WIDTH;
            int y = CANVAS_HEIGHT/3;
            int ecuacion1, ecuacion2 = 0;
            setBackground(CANVAS_BACKGROUND);
            g.drawLine(0, y, x, y);
            ecuacion1 = calculaEcuacion(0,y,x,y);
            System.out.println(ecuacion1);
            g.drawLine(0, y*2, x, y*2);
            ecuacion2 = calculaEcuacion(0,y*2,x,y*2);
            System.out.println(ecuacion2);
            g.setColor(Color.RED);
            //g.drawLine((int) xVal[0],(int) yVal[0],(int) xVal[0],(int) yVal[0]);
            if (xVal.length != 0){
            	for (int i = 0; i < xVal.length;i++){
	            	g.drawLine(xVal[i], yVal[i],xVal[i],yVal[i]);
	            	g.drawOval(xVal[i], yVal[i], 20, 20);
            	}
            }
        }
        
        public int calculaEcuacion(int x0, int y0, int x1, int y1){
        	  int dx = x1 - x0;
        	  int dy = y1 - y0;

        	  if (dx != 0){
        	    float m = (float) dy / (float) dx;
        	    float b = y0 - m*x0;
        	    if(x1 > x0)
        	      dx = 1;
        	    else
        	      dx = -1;
        	    while (x0 != x1) {
        	      x0 += dx;
        	      y0 = Math.round(m*x0 + b);
        	    }
        }		return y0;
    }
   }   
}
