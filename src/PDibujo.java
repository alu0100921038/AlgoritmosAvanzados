package practica10;

import practica10.Hilo;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.util.Random;

import javax.swing.JButton;
import javax.swing.JPanel;

public class PDibujo extends JPanel {
 private int ancho;
 private int alto;
 private int anchoCelda, altoCelda;
 private int numeroCasillas;
 private boolean notFinish = false;
 private int x;
 private int y;
 private Color c;
 
 public PDibujo(int num) {
	 numeroCasillas = num;
 }

 public void paint(Graphics g){
	 
	 
  this.ancho=(int)this.getSize().getWidth();
  this.alto=(int)this.getSize().getHeight();
  x = ancho/2;
  y = alto/2;
  int anchoCelda=(int)(this.getSize().getWidth()/numeroCasillas);
  int altoCelda=(int)(this.getSize().getHeight()/numeroCasillas);
  Color c;
  c=new Color(255,255,255);
  g.setColor(c);
  g.fillRect(0, 0, this.ancho, this.alto);        
  c=new Color(180,180,180);
  g.setColor(c);
  int i; 
  for(i=anchoCelda; i <this.ancho-anchoCelda; i+=anchoCelda){
   g.drawLine(i, 0, i, this.alto);
  }
  for(i=altoCelda; i<this.alto-altoCelda; i+=altoCelda){
   g.drawLine(0, i, this.ancho, i);
  }
  // /**
  //new Thread(new Hilo(this, g)).start();
  while (!notFinish) {
	  Random rand = new Random(System.currentTimeMillis());
	  int movement = ((int) (rand.nextDouble() * 4.0));
	  System.out.println("x vale: " + this.x + " e y vale: " + this.y);
	  System.out.println(movement);
	  switch (movement) {
	  case 0: //Move Left
		  if (this.x - this.anchoCelda >= 0) {
			  g.setColor(Color.RED);
			  g.drawLine(this.x, this.y, this.x-this.anchoCelda, this.y);
			  this.x -= this.anchoCelda;
		  }		  
		  else {
			  System.out.println("No se pudo mover a la izquierda");
			  notFinish = true;
		  }
		  break;
	  case 1: //Move Right
		  if (this.x + this.anchoCelda <= this.ancho) {
			  g.setColor(Color.RED);
			  g.drawLine(this.x, this.y, this.x+anchoCelda, this.y);
		  	  this.x += anchoCelda;
		  }
		  else {
			  System.out.println("No se pudo mover a la derecha");
			  notFinish = true;
		  }
		  break;
	  case 2: //Move Up
		  if (this.y - altoCelda >= 0) {
			  g.setColor(Color.RED);
			  g.drawLine(this.x, this.y, this.x, this.y-altoCelda);
			  this.y -= altoCelda;
		  }
		  else {
			  System.out.println("No se pudo mover arriba");
			  notFinish = true;
		  }
		  break;
	  case 3: //Move Down
		  if (y + altoCelda <= this.alto) {
			  g.setColor(Color.RED);
			  g.drawLine(this.x, this.y, this.x, this.y+altoCelda);
			  this.y += altoCelda;
		  }
		  else {
			  System.out.println("No se pudo mover abajo");
			  notFinish = true;
		  }
		  break;
	  default:
		  break;
	  }
	  try {
		Thread.sleep(1000);
	} catch (InterruptedException e) {
		
		e.printStackTrace();
	}
		   
   }
  }
public boolean isNotFinish() {
	return notFinish;
}

public int getX() {
	return x;
}

public int getY() {
	return y;
}

public void setX(int numero) {
	this.x = numero;
}

public void setY(int numero) {
	this.y = numero;
}

public void setColor(Color c) {
	this.c = c;
}

public int getAncho() {
	return ancho;
}

public void setAncho(int numero) {
	this.ancho = numero;
}

public int getAlto() {
	return alto;
}

public void setAlto(int numero) {
	this.alto = numero;
}

public int getNumeroCasillas() {
	return numeroCasillas;
}

public int getAnchoCelda() {
	return anchoCelda;
}

public int getAltoCelda() {
	return altoCelda;
}

public void setNotFinish(boolean notFinish) {
	this.notFinish = notFinish;
}
 }

 
 