/**
 * 中国象棋第二版
 * @author WY
 * @date 2016-05-20
 */
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
import java.util.*;
import java.io.*;

public class NewChess{
	public static void main(String[] args){
		new ChessMainFrame("New Chinese Chess");
	}
}

class ChessMainFrame extends JFrame implements ActionListener, Runnable{
	JLabel play[] = new JLabel[32];		// 棋子32粒
	JLabel image;
	Container con;
	JToolBar jmain;
	JButton anew;
	JButton repent;
	JButton exit;
	JLabel text;
	Vector Var;		// 保存当前操作
	ChessRule rule;
	/*
	 * 单击棋子
	 * chessManClick = true 闪烁棋子，给线程响应
	 * chessManClick = false 吃棋子，停止闪烁，给线程响应
	 */
	boolean chessManClick;
	/*
	 * 控制玩家走棋
	 * chessPlayClick = 1 黑棋走
	 * chessPlayClick = 2 红棋走，默认红棋
	 * chessPlayClick = 3 不能走棋
	 */
	int chessPlayClick = 2;
	
	Thread tmain;
	static int Man;
	static int i;
	
	ChessMainFrame(){
		new ChessMainFrame("new Chinese chess game");
	}
	
	ChessMainFrame(String Title){
		con = this.getContentPane();
		con.setLayout(null);
		
		rule = new ChessRule();
		Var = new Vector();
		
		jmain = new JToolBar();
		text = new JLabel("Welcome game");
		// 鼠标放上时的提示信息
		text.setToolTipText("guide");
		anew = new JButton("new game");
		anew.setToolTipText("restart a new game");
		exit = new JButton("exit");
		exit.setToolTipText("exit the chess system");
		repent = new JButton("repent");
		repent.setToolTipText("go back last step");
		
		jmain.setLayout(new GridLayout(0, 4));
		jmain.add(anew);
		jmain.add(repent);
		jmain.add(exit);
		jmain.add(text);
		jmain.setBounds(0, 0, 558, 30);
		con.add(jmain);
		
		drawChessMan();	// 添加棋子
		
		anew.addActionListener(this);
		repent.addActionListener(this);
		exit.addActionListener(this);
		
		for (int i = 0; i < 32; i++){
			con.add(play[i]);
			play[i].addMouseListener((MouseListener) this);
		}
		
		con.add(image = new JLabel(new ImageIcon("image\\Main.GIF")));
		image.setBounds(0, 30, 558, 620);
		image.addMouseListener((MouseListener) this);
		
		// 注册窗体关闭监听
		this.addWindowListener(
			new WindowAdapter(){
				public void windowClosing(WindowEvent wevent){
					System.exit(0);
				}
			}
		);
		
		Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
		Dimension frameSize = this.getSize();
		if (frameSize.height > screenSize.height){
			frameSize.height = screenSize.height;
		}
		if (frameSize.width > screenSize.width){
			frameSize.width = screenSize.width;
		}
		
		this.setLocation((screenSize.width - frameSize.width) / 2 - 280,
			(screenSize.height - frameSize.height) / 2 - 350);
		
		// setup
		this.setIconImage(new ImageIcon("image\\redGeneral.GIF").getImage());
		this.setResizable(false);
		this.setTitle(Title);
		this.setSize(558, 670);
		this.show();
	}
	
	// 添加棋子的方法
	public void drawChessMan(){
		int i;
		int k;
		Icon in;	// 图标
		
		// Black 
		{
			String[] piecesIcon = { "image\\blackCar.GIF", "image\\blackHorse.GIF", "image\\blackElephant.GIF", 
					"image\\blackChap.GIF", "image\\blackGeneral.GIF", "image\\blackChap.GIF", "image\\blackElephant.GIF", 
					"image\\blackHorse.GIF", "image\\blackCar.GIF", "image\\blackCannon.GIF", "image\\blackSoldier.GIF" };
			String[] peicesName = { "car 1", "horse 1", "elephant 1", "chap 1", "general 1", "chap 1", "elephant 1", "horse 1", 
					"car 1", "cannon 1", "soldier 1"};
			for (i = 0, k = 24; i < 9; i++, k += 57){
				in = new ImageIcon(piecesIcon[i]);
				play[i] = new JLabel(in);
				play[i].setBounds(k, 56, 55, 55);
				play[i].setName(peicesName[i]);
			}
			// 炮
			in = new ImageIcon(piecesIcon[9]);
			for (i = 9, k = 81; i < 11; i++, k += 342){
				play[i] = new JLabel(in);
				play[i].setBounds(k, 170, 55, 55);
				play[i].setName(peicesName[9]);
			}
			// 卒
			in = new ImageIcon(piecesIcon[10]);
			for (i = 11, k = 24; i < 16; k += 114){
				play[i] = new JLabel(in);
				play[i].setBounds(k, 227, 55, 55);
				play[i].setName(peicesName[10]);
			}
		}
		// Red 
		{
			String[] piecesIconR = { "image\\redCar.GIF", "image\\redHorse.GIF", "image\\redElephant.GIF", 
					"image\\redChap.GIF", "image\\redGeneral.GIF", "image\\redChap.GIF", "image\\redElephant.GIF", 
					"image\\redHorse.GIF", "image\\redCar.GIF", "image\\redCannon.GIF", "image\\redSoldier.GIF" };
			String[] peicesNameR = { "car 2", "horse 2", "elephant 2", "chap 2", "general 2", "chap 2", "elephant 2", "horse 2", 
					"car 2", "cannon 2", "soldier 2"};
			for (i = 16, k = 24; i < 25; i++, k += 57){
				in = new ImageIcon(piecesIconR[i-16]);
				play[i] = new JLabel(in);
				play[i].setBounds(k, 569, 55, 55);
				play[i].setName(peicesNameR[i-16]);
			}
			// 炮
			in = new ImageIcon(piecesIconR[9]);
			for (i = 25, k = 81; i < 27; i++, k += 342){
				play[i] = new JLabel(in);
				play[i].setBounds(k, 455, 55, 55);
				play[i].setName(peicesNameR[9]);
			}
			// 卒
			in = new ImageIcon(piecesIconR[10]);
			for (i = 27, k = 24; i < 32; k += 114){
				play[i] = new JLabel(in);
				play[i].setBounds(k, 398, 55, 55);
				play[i].setName(peicesNameR[10]);
			}
		}
	}
	
	// 线程方法控制棋子闪烁
	public void run(){
		while (true){
			if (chessManClick){	// 单击棋子第一下，开始闪烁
				play[Man].setVisible(false);
				try{
					tmain.sleep(200);
				}
				catch (Exception e){
					// TODO
				}
				
				play[Man].setVisible(true);
			}
			else{	// 闪烁当前提示信息
				text.setVisible(false);
				try{
					tmain.sleep(250);
				}
				catch (Exception e){
					// TODO
				}
				
				text.setVisible(true);
			}
			
			try{
				tmain.sleep(350);
			}
			catch (Exception e){
				
			}
		}
	}
	
	// 获得棋子红黑属性
	private char getBR(String s){
		return s.charAt(s.length() - 1);
	}
	
	// 红旗走棋
	private void redMove(MouseEvent mevent)
	{
		int x = play[Man].getX();
		int y = play[Man].getY();
		
		switch(Man){
			case 16: case 24:
				rule.carMRule(play[Man], play, mevent);
				break;
			case 17: case 23:
				rule.horseMRule(play[Man], play, mevent);
				break;
			case 18: case 22:
				rule.elephantMRule(play[Man], play, mevent);
				break;
			case 19: case 21:
				rule.chapMRule(play[Man], mevent);
				break;
			case 20:
				rule.generalMRule(play[Man], mevent);
				break;
			case 25: case 26:
				rule.cannonMRule(play[Man], play, mevent);
				break;
			case 27: case 28: case 29: case 30: case 31:
				rule.soldierMRule(play[Man], mevent);
				break;
		}
		// 是否走错棋
		if (x == play[Man].getX() && y == play[Man].getY()){
			text.setText(" Red move");
			chessPlayClick = 2;
		}
		else{
			text.setText(" black move");
			chessPlayClick = 1;
		}
	}
	
	// 黑棋走棋
	private void blackMove(MouseEvent mevent){
		int x = play[Man].getX();
		int y = play[Man].getY();
		
		switch(Man){
			case 0: case 8:
				rule.carMRule(play[Man], play, mevent);
				break;
			case 1: case 7:
				rule.horseMRule(play[Man], play, mevent);
				break;
			case 2: case 6:
				rule.elephantMRule(play[Man], play, mevent);
				break;
			case 3: case 5:
				rule.chapMRule(play[Man], mevent);
				break;
			case 4:
				rule.generalMRule(play[Man], mevent);
				break;
			case 9: case 10:
				rule.cannonMRule(play[Man], play, mevent);
				break;
			case 11: case 12: case 13: case 14: case 15:
				rule.soldierMRule(play[Man], mevent);
				break;
		}
		// 是否走错棋
		if (x == play[Man].getX() && y == play[Man].getY()){
			text.setText(" black move");
			chessPlayClick = 1;
		}
		else{
			text.setText(" Red move");
			chessPlayClick = 2;
		}
	}
	
	// 单击棋子方法
	public void mouseClicked(MouseEvent mevent){
		System.out.println("Mouse");
		
		// 启动线程
		if (tmain == null){
			tmain = new Thread(this);
			tmain.start();
		}
		
		// 单击棋盘
		if (mevent.getSource().equals(image)){
			// 红方走棋
			if (chessPlayClick == 2 && getBR(play[Man].getName()) == '2'){
				redMove(mevent);
			}
			// 黑方走棋
			else if (chessPlayClick == 1 && getBR(play[Man].getName()) == '1'){	
				blackMove(mevent);
			}
			
			chessManClick = false;
		}
		else{
			// 第一次单击棋子，闪烁
			if (!chessManClick){
				for (int i = 0; i < 32; i++){
					if (mevent.getSource().equals(play[i])){
						// 告诉线程，使其闪烁
						Man = i;
						chessManClick = true;
						break;
					}
				}
			}
			else if (chessManClick){	// 第二次单击棋子，吃棋
				chessManClick = false;
				for (int i = 0; i < 32; i++){
					// 找到被吃的棋子
					if (mevent.getSource().equals(play[i])){
						if (chessPlayClick == 2 && getBR(play[Man].getName()) == '2'){
							redMove(mevent);
						}
						else if (chessPlayClick == 1 && getBR(play[Man].getName()) == '1'){
							blackMove(mevent);
						}
					}
				}
				// 是否胜利
				if (!play[20].isVisible()){
					JOptionPane.showConfirmDialog(
						this,
						"Balck win",
						"game over",
						JOptionPane.DEFAULT_OPTION, JOptionPane.WARNING_MESSAGE
					);
					chessPlayClick = 3;
					text.setText(" black win");
				}
				else if (!play[4].isVisible()){
					JOptionPane.showConfirmDialog(
						this,
						"red win",
						"game over",
						JOptionPane.DEFAULT_OPTION,
						JOptionPane.WARNING_MESSAGE
					);
					chessPlayClick = 3;
					text.setText(" red win");
				}
			}
		}
	}
	
	public void mousePressed(MouseEvent mevent){
		
	}
	
	public void mouseReleased(MouseEvent mevent){
		
	}
	
	public void mouseEntered(MouseEvent mevent){
		
	}
	
	public void mouseExited(MouseEvent mevent){
		
	}
	
	// 定义按钮事件响应
	public void actionPerformed(ActionEvent aevent){
		// 重新开始按钮
		if (aevent.getSource().equals(anew)){
			int i;
			int k;
			
			// 重新排棋
			for (i = 0, k = 24; i < 9; i++, k += 57){
				play[i].setBounds(k, 56, 55, 55);
			}
			for (i = 9, k = 81; i < 11; i++, k += 342){
				play[i].setBounds(k, 170, 55, 55);
			}
			for (i = 11, k = 24; i < 16; i++, k += 114){
				play[i].setBounds(k, 227, 55, 55);
			}
			for (i = 16, k = 24; i < 25; i++, k += 57){
				play[i].setBounds(k, 569, 55, 55);
			}
			for (i = 25, k = 81; i < 27; i++, k += 342){
				play[i].setBounds(k, 455, 55, 55);
			}
			for (i = 27, k = 24; i < 32; i++, k += 114){
				play[i].setBounds(k, 398, 55, 55);
			}
			
			chessPlayClick = 2;
			text.setText(" red move");
			for (i = 0; i < 32; i++){
				play[i].setVisible(true);
			}
			Var.clear();	// 清楚记录
		}
		else if (aevent.getSource().equals(repent)){
			try{
				String s = (String)Var.get(Var.size() - 4);
				int x = Integer.parseInt((String)Var.get(Var.size() - 3));
				int y = Integer.parseInt((String)Var.get(Var.size() - 2));
				int M = Integer.parseInt((String)Var.get(Var.size() - 1));
				
				play[M].setVisible(true);
				play[M].setBounds(x, y, 55, 55);
				
				if (getBR(play[M].getName()) == '1'){
					text.setText(" black move");
					chessPlayClick = 1;
				}
				else{
					text.setText(" red move");
					chessPlayClick = 2;
				}
				
				Var.remove(Var.size() - 4);
				Var.remove(Var.size() - 3);
				Var.remove(Var.size() - 2);
				Var.remove(Var.size() - 1);
				
				chessManClick = false;
			}
			catch (Exception e){
				
			}
		}
		else if (aevent.getSource().equals(exit)){
			int j = JOptionPane.showConfirmDialog(
				this,
				"exit?",
				"exit",
				JOptionPane.YES_OPTION,
				JOptionPane.QUESTION_MESSAGE
			);
			if (j == JOptionPane.YES_OPTION){
				System.exit(0);
			}
		}
	}
	
	class ChessRule{
		/*
		 * 很多规则不知所云，错误不知道多少，需要重改
		 */
		private void saveCurrentStep(JLabel play, int m){
			Var.add(String.valueOf(play.isVisible()));
			Var.add(String.valueOf(play.getX()));
			Var.add(String.valueOf(play.getY()));
			Var.add(String.valueOf(m));
		}
		
		public void carMRule(JLabel play, JLabel[] playA, MouseEvent mevent){
			int barrier = 0;
			// up - down
			if ((play.getX() - mevent.getX() <= 0) &&
				(play.getX() - mevent.getX() >= -55)){
				for (int i = 56; i <= 571; i += 57){
					if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
						for (int j = 0; j < 32; j++){	// 所有棋子
							if (playA[j].getX() - play.getX() >= -27 &&
								(playA[j].getX() - play.getX() <= 27) &&
								(getBR(playA[j].getName()) != getBR(play.getName())) &&
								(playA[j].isVisible())){
								// 从起点到终点(左到右)
								for (int k = play.getY() + 57; k < i; k += 57){
									// 大于起点，小于终点，即可知道是否有棋子在中间
									if (playA[j].getY() > play.getY() && playA[j].getY() < i){
										barrier++;
										break;
									}
								}
								// 从终点到起点(右到左)
								for (int k = i + 57; k < play.getY(); k +=  57){
									if (playA[j].getY() < play.getY() && playA[j].getY() > i){
										barrier++;
										break;
									}
								}
							}
						}// for
						// 无棋子则，可以移动
						if (barrier == 0){
							saveCurrentStep(play, Man);
							play.setBounds(play.getX(), i, 55, 55);
							break;
						}
					}// if
				}// for
			}// if
			// left-right
			else if (play.getY() - mevent.getY() >= -27 && play.getY() - mevent.getY() <= 27){
				for (int i = 24; i <= 480; i += 57){
					if (i - mevent.getX() >= -55 && i - mevent.getX() <= 0){
						for (int j = 0; j < 32; j++){
							if (playA[j].getY() - play.getY() >= -27 &&
								(playA[j].getY() - play.getY() <= 27) &&
								(getBR(playA[j].getName()) != getBR(play.getName())) &&
								playA[j].isVisible()){
								// 起点到终点 (从上到下)
								for (int k = getX() + 57; k < i; k += 57){
									if (playA[j].getX() > play.getY() && playA[j].getY() < i){
										barrier++;
										break;
									}
								}
							}
						}
						if (barrier == 0){
							saveCurrentStep(play, Man);
							play.setBounds(i, play.getY(), 55, 55);
							break;
						}
					}
				}
			}
		}
		
		public void carERule(JLabel play, JLabel playTake, JLabel[] playA){
			int barrier = 0;
			// 吃棋不能是自己方的棋子
			if (getBR(play.getName()) != getBR(playTake.getName())){
				if (play.getX() == playTake.getX())	// 说明在竖线上 X相等
				{
					for (int j = 0; j < 32; j++){
						if (playA[j].isVisible() && playA[j].getX() == play.getX()){
							if ((playA[j].getY() < play.getY() && playA[j].getY() > playTake.getY()) ||
							(playA[j].getY() > play.getY() && playA[j].getY() < playTake.getY())){
								barrier++;
							}
						}
					}
				}
				else if (play.getY() == playTake.getY()){	// 说明在横线上 Y相等
					for (int j = 0; j < 32; j++){
						if (playA[j].isVisible() && playA[j].getY() == play.getY()){
							if ((playA[j].getX() < play.getX() && playA[j].getX() > playTake.getX()) ||
							(playA[j].getX() > play.getX() && playA[j].getX() < playTake.getX())){
								barrier++;
							}
						}
					}
				}
				
				if (barrier == 0){
					saveCurrentStep(play, Man);
					saveCurrentStep(playTake, i);
					playTake.setVisible(false);
					play.setBounds(playTake.getX(), playTake.getY(), 55, 55);
				}
			}
		}
		
		public void horseMRule(JLabel play, JLabel[] playA, MouseEvent mevent){
			int x = 0;
			int y = 0;
			int barrier = 0;
			
			// up-left
			if ((play.getX() - mevent.getX() >= 2) &&
				(play.getX() - mevent.getX() <= 57) &&
				(play.getY() - mevent.getY() >= 87) &&
				(play.getY() - mevent.getY() <= 141)){
				// valid y
				for (int i = 56; i <= 571; i += 57){
					if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
						y = i;
						break;
					}
				}
				// valid x
				for (int i = 24; i < 480; i += 57){
					if (i - mevent.getX() >= -55 && i - mevent.getX() <= 0){
						x = i;
						break;
					}
				}
				// 是否有棋子挡住马脚  正前方
				for (int j = 0; j < 32; j++){
					if (playA[j].isVisible() &&
						(play.getX() - playA[j].getX() == 0) &&
						(play.getY() - playA[j].getY() == 57)){
						barrier = 1;
						break;
					}
				}
			}
			// left-up
			else if ((play.getX() - mevent.getX() >= 70) &&
				(play.getX() - mevent.getX() <= 130) &&
				(play.getY() - mevent.getY() >= 27) &&
				(play.getY() - mevent.getY() <= 86)){
				// valid y
				for (int i = 56; i <= 571; i += 57){
					if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
						y = i;
						break;
					}
				}
				// valid x
				for (int i = 24; i < 480; i += 57){
					if (i - mevent.getX() >= -55 && i - mevent.getX() <= 0){
						x = i;
						break;
					}
				}
				// 是否有棋子挡住马脚  正前方
				for (int j = 0; j < 32; j++){
					if (playA[j].isVisible() &&
						(play.getX() - playA[j].getX() == 57) &&
						(play.getY() - playA[j].getY() == 0)){
						barrier = 1;
						break;
					}
				}
			}
			// down-right
			else if ((play.getX() - mevent.getX() >= -87) &&
				(play.getX() - mevent.getX() <= -2) &&
				(play.getY() - mevent.getY() >= -141) &&
				(play.getY() - mevent.getY() <= -87)){
				// valid y
				for (int i = 56; i <= 571; i += 57){
					if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
						y = i;
						break;
					}
				}
				// valid x
				for (int i = 24; i < 480; i += 57){
					if (i - mevent.getX() >= -55 && i - mevent.getX() <= 0){
						x = i;
						break;
					}
				}
				// 是否有棋子挡住马脚  正前方
				for (int j = 0; j < 32; j++){
					if (playA[j].isVisible() &&
						(play.getX() - playA[j].getX() == 0) &&
						(play.getY() - playA[j].getY() == -57)){
						barrier = 1;
						break;
					}
				}
			}
			// up-right
			else if ((play.getX() - mevent.getX() >= -87) &&
				(play.getX() - mevent.getX() <= -30) &&
				(play.getY() - mevent.getY() >= 87) &&
				(play.getY() - mevent.getY() <= 141)){
				// valid y
				for (int i = 56; i <= 571; i += 57){
					if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
						y = i;
						break;
					}
				}
				// valid x
				for (int i = 24; i < 480; i += 57){
					if (i - mevent.getX() >= -55 && i - mevent.getX() <= 0){
						x = i;
						break;
					}
				}
				// 是否有棋子挡住马脚  正前方
				for (int j = 0; j < 32; j++){
					if (playA[j].isVisible() &&
						(play.getX() - playA[j].getX() == 0) &&
						(play.getY() - playA[j].getY() == 57)){
						barrier = 1;
						break;
					}
				}
			}
			// down-left
			else if ((play.getX() - mevent.getX() >= 10) &&
				(play.getX() - mevent.getX() <= 87) &&
				(play.getY() - mevent.getY() >= -141) &&
				(play.getY() - mevent.getY() <= -87)){
				// valid y
				for (int i = 56; i <= 571; i += 57){
					if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
						y = i;
						break;
					}
				}
				// valid x
				for (int i = 24; i < 480; i += 57){
					if (i - mevent.getX() >= -55 && i - mevent.getX() <= 0){
						x = i;
						break;
					}
				}
				// 是否有棋子挡住马脚  正下方
				for (int j = 0; j < 32; j++){
					if (playA[j].isVisible() &&
						(play.getX() - playA[j].getX() == 0) &&
						(play.getY() - playA[j].getY() == -57)){
						barrier = 1;
						break;
					}
				}
			}
			// right-up
			else if ((play.getX() - mevent.getX() >= -141) &&
				(play.getX() - mevent.getX() <= -87) &&
				(play.getY() - mevent.getY() >= 30) &&
				(play.getY() - mevent.getY() <= 87)){
				// valid y
				for (int i = 56; i <= 571; i += 57){
					if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
						y = i;
						break;
					}
				}
				// valid x
				for (int i = 24; i < 480; i += 57){
					if (i - mevent.getX() >= -55 && i - mevent.getX() <= 0){
						x = i;
						break;
					}
				}
				// 是否有棋子挡住马脚  正右方
				for (int j = 0; j < 32; j++){
					if (playA[j].isVisible() &&
						(play.getX() - playA[j].getX() == -57) &&
						(play.getY() - playA[j].getY() == 0)){
						barrier = 1;
						break;
					}
				}
			}
			// right-down
			else if ((play.getX() - mevent.getX() >= -141) &&
				(play.getX() - mevent.getX() <= -87) &&
				(play.getY() - mevent.getY() >= -87) &&
				(play.getY() - mevent.getY() <= -30)){
				// valid y
				for (int i = 56; i <= 571; i += 57){
					if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
						y = i;
						break;
					}
				}
				// valid x
				for (int i = 24; i < 480; i += 57){
					if (i - mevent.getX() >= -55 && i - mevent.getX() <= 0){
						x = i;
						break;
					}
				}
				// 是否有棋子挡住马脚  正右方
				for (int j = 0; j < 32; j++){
					if (playA[j].isVisible() &&
						(play.getX() - playA[j].getX() == -57) &&
						(play.getY() - playA[j].getY() == 0)){
						barrier = 1;
						break;
					}
				}
			}
			// left-down
			else if ((play.getX() - mevent.getX() >= 87) &&
				(play.getX() - mevent.getX() <= 141) &&
				(play.getY() - mevent.getY() >= -87) &&
				(play.getY() - mevent.getY() <= -30)){
				// valid y
				for (int i = 56; i <= 571; i += 57){
					if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
						y = i;
						break;
					}
				}
				// valid x
				for (int i = 24; i < 480; i += 57){
					if (i - mevent.getX() >= -55 && i - mevent.getX() <= 0){
						x = i;
						break;
					}
				}
				// 是否有棋子挡住马脚  正右方
				for (int j = 0; j < 32; j++){
					if (playA[j].isVisible() &&
						(play.getX() - playA[j].getX() == 57) &&
						(play.getY() - playA[j].getY() == 0)){
						barrier = 1;
						break;
					}
				}
			}
			if (barrier == 0){
				saveCurrentStep(play, Man);
				play.setBounds(x, y, 55, 55);
			}
		}
		
		public void horseERule(JLabel play, JLabel playTake, JLabel[] playA){
			int barrier = 0;
			boolean placeValid = false;
			
			if (getBR(play.getName()) != getBR(playTake.getName())){
				// up-left
				if (play.getX() - playTake.getX() == 57 && play.getY() - playTake.getY() == 114){
					placeValid = true;	// 位置是合法的
					// 正前方是否有别的棋子
					for (int j = 0; j < 32; j++){
						if ((playA[j].isVisible()) &&
							(play.getX() - playA[j].getX() == 0) &&
							(play.getY() - playA[j].getY() == 57)){
							barrier = 1;
							break;
						}
					}
				}
				// up-right
				else if (play.getX() - playTake.getX() == -57 && play.getY() - playTake.getY() == 114){
					placeValid = true;	// 位置是合法的
					// 正前方是否有别的棋子
					for (int j = 0; j < 32; j++){
						if ((playA[j].isVisible()) &&
							(play.getX() - playA[j].getX() == 0) &&
							(play.getY() - playA[j].getY() == 57)){
							barrier = 1;
							break;
						}
					}
				}
				// down-left
				else if (play.getX() - playTake.getX() == 57 && play.getY() - playTake.getY() == -114){
					placeValid = true;	// 位置是合法的
					// 正前方是否有别的棋子
					for (int j = 0; j < 32; j++){
						if ((playA[j].isVisible()) &&
							(play.getX() - playA[j].getX() == 0) &&
							(play.getY() - playA[j].getY() == -57)){
							barrier = 1;
							break;
						}
					}
				}
				// down-right
				else if (play.getX() - playTake.getX() == -57 && play.getY() - playTake.getY() == -114){
					placeValid = true;	// 位置是合法的
					// 正前方是否有别的棋子
					for (int j = 0; j < 32; j++){
						if ((playA[j].isVisible()) &&
							(play.getX() - playA[j].getX() == 0) &&
							(play.getY() - playA[j].getY() == -57)){
							barrier = 1;
							break;
						}
					}
				}
				// left-up
				else if (play.getX() - playTake.getX() == 114 && play.getY() - playTake.getY() == 57){
					placeValid = true;	// 位置是合法的
					// 正前方是否有别的棋子
					for (int j = 0; j < 32; j++){
						if ((playA[j].isVisible()) &&
							(play.getX() - playA[j].getX() == 57) &&
							(play.getY() - playA[j].getY() == 0)){
							barrier = 1;
							break;
						}
					}
				}
				// left-down
				else if (play.getX() - playTake.getX() == 114 && play.getY() - playTake.getY() == -57){
					placeValid = true;	// 位置是合法的
					// 正前方是否有别的棋子
					for (int j = 0; j < 32; j++){
						if ((playA[j].isVisible()) &&
							(play.getX() - playA[j].getX() == 57) &&
							(play.getY() - playA[j].getY() == 0)){
							barrier = 1;
							break;
						}
					}
				}
				// right-up
				else if (play.getX() - playTake.getX() == -114 && play.getY() - playTake.getY() == 57){
					placeValid = true;	// 位置是合法的
					// 正前方是否有别的棋子
					for (int j = 0; j < 32; j++){
						if ((playA[j].isVisible()) &&
							(play.getX() - playA[j].getX() == -57) &&
							(play.getY() - playA[j].getY() == 0)){
							barrier = 1;
							break;
						}
					}
				}
				// right-down
				else if (play.getX() - playTake.getX() == -114 && play.getY() - playTake.getY() == -57){
					placeValid = true;	// 位置是合法的
					// 正前方是否有别的棋子
					for (int j = 0; j < 32; j++){
						if ((playA[j].isVisible()) &&
							(play.getX() - playA[j].getX() == -57) &&
							(play.getY() - playA[j].getY() == 0)){
							barrier = 1;
							break;
						}
					}
				}
				// 位置合法，马走日，无障碍
				if (placeValid && barrier == 0){
					saveCurrentStep(play, Man);
					saveCurrentStep(playTake,i);
					playTake.setVisible(false);
					play.setBounds(playTake.getX(), playTake.getY(), 55, 55);
				}
			}
		}
		
		public void elephantMRule(JLabel play, JLabel playA[], MouseEvent mevent){
			int x = 0;
			int y = 0;
			int barrier = 0;
			boolean validPlace = false;
			
			// valid y
			for (int i = 56; i <= 571; i += 57){
				if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
					y = i;
					break;
				}
			}
			// valid x
			for (int i = 24; i <= 480; i += 57){
				if (i - mevent.getX() >= -27 && i - mevent.getX() <= 27){
					x = i;
					break;
				}
			}
			
			// up-left
			if ((play.getX() - mevent.getX() <= 141) &&
				(play.getX() - mevent.getX() >= 87) &&
				(play.getY() - mevent.getY() <= 141) &&
				(play.getY() - mevent.getY() >= 87)){
				validPlace = true;
				// 左上方是否有棋子
				for (int j = 0; j < 32; j++){
					if (playA[j].isVisible() &&
						(play.getX() - playA[j].getX() == 57) &&
						(play.getY() - playA[j].getY() == 57)){
						barrier = 1;
						break;
					}
				}
			}
			// up-right
			else if ((play.getX() - mevent.getX() <= -87) &&
				(play.getX() - mevent.getX() >= -141) &&
				(play.getY() - mevent.getY() <= 141) &&
				(play.getY() - mevent.getY() >= 87)){
				validPlace = true;
				// 右上方是否有棋子
				for (int j = 0; j < 32; j++){
					if (playA[j].isVisible() &&
						(play.getX() - playA[j].getX() == -57) &&
						(play.getY() - playA[j].getY() == 57)){
						barrier = 1;
						break;
					}
				}
			}
			// down-left
			else if ((play.getX() - mevent.getX() <= 141) &&
				(play.getX() - mevent.getX() >= 87) &&
				(play.getY() - mevent.getY() <= -87) &&
				(play.getY() - mevent.getY() >= -141)){
				validPlace = true;
				// 下左方是否有棋子
				for (int j = 0; j < 32; j++){
					if (playA[j].isVisible() &&
						(play.getX() - playA[j].getX() == 57) &&
						(play.getY() - playA[j].getY() == -57)){
						barrier = 1;
						break;
					}
				}
			}
			// down-right
			else if ((play.getX() - mevent.getX() <= -87) &&
				(play.getX() - mevent.getX() >= -141) &&
				(play.getY() - mevent.getY() <= -87) &&
				(play.getY() - mevent.getY() >= -141)){
				validPlace = true;
				// 下右方是否有棋子
				for (int j = 0; j < 32; j++){
					if (playA[j].isVisible() &&
						(play.getX() - playA[j].getX() == -57) &&
						(play.getY() - playA[j].getY() == -57)){
						barrier = 1;
						break;
					}
				}
			}
			
			// 红棋不能过楚河	 黑棋不能过汉界
			if (validPlace && barrier == 0 && ((Man > 15 && y >= 341) || (Man < 16 && y <= 284))){
				saveCurrentStep(play, Man);
				play.setBounds(x, y, 55, 55);
			}
		}
		
		public void elephantERule(JLabel play, JLabel playTake, JLabel[] playA){
			int barrier = 0;
			boolean validPlace = false;
			// left-up 	87+141=2*114
			if ((play.getX() - playTake.getX() >= 87) &&
				(play.getX() - playTake.getX() <= 141) &&
				(play.getY() - playTake.getY() >= 87) &&
				(play.getY() - playTake.getY() <= 141)){
				validPlace = true;
				for (int j = 0; j < 32; j++){
					if (playA[j].isVisible() &&
						(play.getX() - playA[j].getX() == 57) &&
						(play.getY() - playA[j].getY() == 57)){
						barrier = 1;
						break;
					}
				}
			}
			// left-down 	87+141=2*114
			else if ((play.getX() - playTake.getX() >= 87) &&
				(play.getX() - playTake.getX() <= 141) &&
				(play.getY() - playTake.getY() >= -141) &&
				(play.getY() - playTake.getY() <= -87)){
				validPlace = true;
				for (int j = 0; j < 32; j++){
					if (playA[j].isVisible() &&
						(play.getX() - playA[j].getX() == 57) &&
						(play.getY() - playA[j].getY() == -57)){
						barrier = 1;
						break;
					}
				}
			}
			// right-up 	87+141=2*114
			else if ((play.getX() - playTake.getX() >= -141) &&
				(play.getX() - playTake.getX() <= -87) &&
				(play.getY() - playTake.getY() >= 87) &&
				(play.getY() - playTake.getY() <= 141)){
				validPlace = true;
				for (int j = 0; j < 32; j++){
					if (playA[j].isVisible() &&
						(play.getX() - playA[j].getX() == -57) &&
						(play.getY() - playA[j].getY() == 57)){
						barrier = 1;
						break;
					}
				}
			}
			// right-down 	87+141=2*114
			else if ((play.getX() - playTake.getX() >= -141) &&
				(play.getX() - playTake.getX() <= -87) &&
				(play.getY() - playTake.getY() >= -141) &&
				(play.getY() - playTake.getY() <= -87)){
				validPlace = true;
				for (int j = 0; j < 32; j++){
					if (playA[j].isVisible() &&
						(play.getX() - playA[j].getX() == -57) &&
						(play.getY() - playA[j].getY() == -57)){
						barrier = 1;
						break;
					}
				}
			}
			if (validPlace && barrier == 0 && getBR(play.getName()) != getBR(playTake.getName())){
				saveCurrentStep(play, Man);
				saveCurrentStep(playTake, i);
				playTake.setVisible(false);
				play.setBounds(playTake.getX(), playTake.getY(), 55, 55);
			}
		}
		
		public void chapMRule(JLabel play, MouseEvent mevent){
			// up-right
			if ((play.getX() - mevent.getX() >= -114) &&
				(play.getX() - mevent.getX() <= -29) &&
				(play.getY() - mevent.getY() >= 25) &&
				(play.getY() - mevent.getY() <= 90)){
				if ((Man < 16 && (play.getX() + 57 >= 195) && (play.getX() + 57 <= 309) && (play.getY() - 57 <= 170)) ||
					(Man > 15 && (play.getX() + 57 >= 195) && (play.getX() + 57 <= 309) && (play.getY() - 57 >= 455))){
					saveCurrentStep(play, Man);
					play.setBounds(play.getX() + 57, play.getY() - 57, 55, 55);
				}
			}
			// up-left
			else if ((play.getX() - mevent.getX() >= 25) &&
				(play.getX() - mevent.getX() <= 114) &&
				(play.getY() - mevent.getY() >= 20) &&
				(play.getY() - mevent.getY() <= 95)){
				if ((Man < 16 && (play.getX() - 57 >= 195) && (play.getX() - 57 <= 309) && (play.getY() - 57 <= 170)) ||
					(Man > 15 && (play.getX() - 57 >= 195) && (play.getX() - 57 <= 309) && (play.getY() - 57 >= 455))){
					saveCurrentStep(play, Man);
					play.setBounds(play.getX() - 57, play.getY() - 57, 55, 55);
				}
			}
			// down-left
			else if ((play.getX() - mevent.getX() >= 25) &&
				(play.getX() - mevent.getX() <= 114) &&
				(play.getY() - mevent.getY() >= -87) &&
				(play.getY() - mevent.getY() <= -2)){
				if ((Man < 16 && (play.getX() - 57 >= 195) && (play.getX() - 57 <= 309) && (play.getY() + 57 <= 170)) ||
					(Man > 15 && (play.getX() - 57 >= 195) && (play.getX() - 57 <= 309) && (play.getY() + 57 >= 455))){
					saveCurrentStep(play, Man);
					play.setBounds(play.getX() - 57, play.getY() + 57, 55, 55);
				}
			}
			// down- right
			else if ((play.getX() - mevent.getX() >= -114) &&
				(play.getX() - mevent.getX() <= -27) &&
				(play.getY() - mevent.getY() >= -87) &&
				(play.getY() - mevent.getY() <= -2)){
				if ((Man < 16 && (play.getX() + 57 >= 195) && (play.getX() + 57 <= 309) && (play.getY() + 57 <= 170)) ||
					(Man > 15 && (play.getX() + 57 >= 195) && (play.getX() + 57 <= 309) && (play.getY() + 57 >= 455))){
					saveCurrentStep(play, Man);
					play.setBounds(play.getX() + 57, play.getY() + 57, 55, 55);
				}
			}
		}
		
		public void chapERule(JLabel play, JLabel playTake){
			boolean validPlace = false;
			if (playTake.isVisible() && getBR(play.getName()) != getBR(playTake.getName()) &&
				((Man < 16 && playTake.getX() >= 195 && playTake.getX() <= 309 && playTake.getY() <= 170) ||
				(Man >15 && playTake.getX() >= 195 && playTake.getX() <= 309 && playTake.getY() >= 455))){
				// up-left
				if ((play.getX() - playTake.getX() == 57) &&
					(play.getY() - playTake.getY() == 57)){
					validPlace = true;
				}
				// up-right
				else if ((play.getX() - playTake.getX() == -57) &&
					(play.getY() - playTake.getY() == 57)){
					validPlace = true;
				}
				// down-left
				else if ((play.getX() - playTake.getX() == 57) &&
					(play.getY() - playTake.getY() == -57)){
					validPlace = true;
				}
				// down-right
				else if ((play.getX() - playTake.getX() == -57) &&
					(play.getY() - playTake.getY() == -57)){
					validPlace = true;
				}
				
				if (validPlace){
					saveCurrentStep(play, Man);
					saveCurrentStep(playTake, i);
					playTake.setVisible(false);
					play.setBounds(playTake.getX(), playTake.getY(), 55, 55);
				}
			}
		}
		
		public void generalMRule(JLabel play, MouseEvent mevent){
			// up
			if ((play.getX() - mevent.getX() >= -27) &&
				(play.getX() - mevent.getX() <= 27) &&
				(play.getY() - mevent.getY() >= 27) &&
				(play.getY() - mevent.getY() <= 87)){
				if (mevent.getX() >= 195 && mevent.getX() <= 359 && 
					((Man == 4 &&  mevent.getY() <= 170) || 
						(Man == 20 && mevent.getY() >= 455)))
				{
					saveCurrentStep(play, Man);
					play.setBounds(play.getX(), play.getY() - 57, 55, 55);
				}
			}
			// down
			else if ((play.getX() - mevent.getX() >= -27) &&
				(play.getX() - mevent.getX() <= 27) &&
				(play.getY() - mevent.getY() >= -87) &&
				(play.getY() - mevent.getY() <= -27)){
				if (mevent.getX() >= 195 && mevent.getX() <= 359 && 
					((Man == 4 &&  mevent.getY() <= 170) || 
						(Man == 20 && mevent.getY() >= 455)))
				{
					saveCurrentStep(play, Man);
					play.setBounds(play.getX(), play.getY() + 57, 55, 55);
				}
			}
			// left
			else if ((play.getX() - mevent.getX() >= 27) &&
				(play.getX() - mevent.getX() <= 87) &&
				(play.getY() - mevent.getY() >= -27) &&
				(play.getY() - mevent.getY() <= 27)){
				if (mevent.getX() >= 195 && mevent.getX() <= 359 && 
					((Man == 4 &&  mevent.getY() <= 170) || 
						(Man == 20 && mevent.getY() >= 455)))
				{
					saveCurrentStep(play, Man);
					play.setBounds(play.getX() - 57, play.getY(), 55, 55);
				}
			}
			// right
			else if ((play.getX() - mevent.getX() >= -87) &&
				(play.getX() - mevent.getX() <= -27) &&
				(play.getY() - mevent.getY() >= -27) &&
				(play.getY() - mevent.getY() <= 27)){
				if (mevent.getX() >= 195 && mevent.getX() <= 359 && 
					((Man == 4 &&  mevent.getY() <= 170) || 
						(Man == 20 && mevent.getY() >= 455)))
				{
					saveCurrentStep(play, Man);
					play.setBounds(play.getX() + 57, play.getY(), 55, 55);
				}
			}
		}
		
		public void generalERule(JLabel play, JLabel playTake){
			boolean validPlace = false;
			
			if (playTake.isVisible() && getBR(playTake.getName()) != getBR(play.getName()) &&
				playTake.getX() >= 195 && playTake.getX() <= 309 &&
				((Man == 4 && playTake.getY() <= 170) || (Man == 20 && playTake.getY() >= 455))){
				// up
				if (play.getX() - playTake.getX() == 0 && play.getY() - playTake.getY() == 57){
					validPlace = true;
				}
				// down
				else if (play.getX() - playTake.getX() == 0 && play.getY() - playTake.getY() == -57){
					validPlace = true;
				}
				// left
				else if (play.getX() - playTake.getX() == 57 && play.getY() - playTake.getY() == 0){
					validPlace = true;
				}
				// right
				else if (play.getX() - playTake.getX() == -57 && play.getY() - playTake.getY() == 0){
					validPlace = true;
				}
				
				if (validPlace){
					saveCurrentStep(play, Man);
					saveCurrentStep(playTake, i);
					playTake.setVisible(false);
					play.setBounds(playTake.getX(), playTake.getY(), 55, 55);
				}
			}
		}
		
		public void cannonMRule(JLabel play, JLabel[] playA, MouseEvent mevent){
			int barrier = 0;
			// up - down
			if ((play.getX() - mevent.getX() <= 0) &&
				(play.getX() - mevent.getX() >= -55)){
				for (int i = 56; i <= 571; i += 57){
					if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
						for (int j = 0; j < 32; j++){	// 所有棋子
							if (playA[j].getX() - play.getX() >= -27 &&
								(playA[j].getX() - play.getX() <= 27) &&
								(getBR(playA[j].getName()) != getBR(play.getName())) &&
								(playA[j].isVisible())){
								// 从起点到终点(左到右)
								for (int k = play.getY() + 57; k < i; k += 57){
									// 大于起点，小于终点，即可知道是否有棋子在中间
									if (playA[j].getY() > play.getY() && playA[j].getY() < i){
										barrier++;
										break;
									}
								}
								// 从终点到起点(右到左)
								for (int k = i + 57; k < play.getY(); k +=  57){
									if (playA[j].getY() < play.getY() && playA[j].getY() > i){
										barrier++;
										break;
									}
								}
							}
						}// for
						// 无棋子则，可以移动
						if (barrier == 0){
							saveCurrentStep(play, Man);
							play.setBounds(play.getX(), i, 55, 55);
							break;
						}
					}// if
				}// for
			}// if
			// left-right
			else if (play.getY() - mevent.getY() >= -27 && play.getY() - mevent.getY() <= 27){
				for (int i = 24; i <= 480; i += 57){
					if (i - mevent.getX() >= -55 && i - mevent.getX() <= 0){
						for (int j = 0; j < 32; j++){
							if (playA[j].getY() - play.getY() >= -27 &&
								(playA[j].getY() - play.getY() <= 27) &&
								(getBR(playA[j].getName()) != getBR(play.getName())) &&
								playA[j].isVisible()){
								// 起点到终点 (从上到下)
								for (int k = getX() + 57; k < i; k += 57){
									if (playA[j].getX() > play.getY() && playA[j].getY() < i){
										barrier++;
										break;
									}
								}
							}
						}
						if (barrier == 0){
							saveCurrentStep(play, Man);
							play.setBounds(i, play.getY(), 55, 55);
							break;
						}
					}
				}
			}
		}
		
		// 炮吃棋
		public void cannonERule(JLabel play, JLabel playTake, JLabel[] playA, MouseEvent mevent){
			int barrier = 0;
			// 吃棋不能是自己方的棋子
			if (getBR(play.getName()) != getBR(playTake.getName())){
				if (play.getX() == playTake.getX())	// 说明在竖线上 X相等
				{
					for (int j = 0; j < 32; j++){
						if (playA[j].isVisible() && playA[j].getX() == play.getX()){
							if ((playA[j].getY() < play.getY() && playA[j].getY() > playTake.getY()) ||
							(playA[j].getY() > play.getY() && playA[j].getY() < playTake.getY())){
								barrier++;
							}
						}
					}
				}
				else if (play.getY() == playTake.getY()){	// 说明在横线上 Y相等
					for (int j = 0; j < 32; j++){
						if (playA[j].isVisible() && playA[j].getY() == play.getY()){
							if ((playA[j].getX() < play.getX() && playA[j].getX() > playTake.getX()) ||
							(playA[j].getX() > play.getX() && playA[j].getX() < playTake.getX())){
								barrier++;
							}
						}
					}
				}
				
				if (barrier == 1){	// Chess=1表示车，=0表示炮
					saveCurrentStep(play, Man);
					saveCurrentStep(playTake, i);
					playTake.setVisible(false);
					play.setBounds(playTake.getX(), playTake.getY(), 55, 55);
				}
			}
		}
		
		// 卒移动规则
		public void soldierMRule(JLabel play, MouseEvent mevent){
			if (Man < 16){	// black
				saveCurrentStep(play, Man);
				// down
				if ((mevent.getX() - play.getX() >= 0 ) &&
					(mevent.getX() - play.getX() <= 55) &&
					(mevent.getY() - play.getY() >= 27) &&
					(mevent.getY() - play.getY() <= 86)){
					play.setBounds(play.getX(), play.getY() + 57, 55, 55);
				}
				// right
				else if ((mevent.getX() - play.getX() >= 57) &&
						(mevent.getX() - play.getX() <= 112) &&
						(play.getY() >= 284)){
					play.setBounds(play.getX() + 57, play.getY(), 55, 55);
				}
				// left
				else if ((mevent.getX() - play.getX() >= -58) &&
						(mevent.getX() - play.getX() <= -2) &&
						(play.getY() >= 284)){
					play.setBounds(play.getX() - 57, play.getY(), 55, 55);
				}
			}
			else{	// red
				saveCurrentStep(play, Man);
				// up
				if ((mevent.getX() - play.getX() >= 0 ) &&
					(mevent.getX() - play.getX() <= 55) &&
					(mevent.getY() - play.getY() >= -86) &&
					(mevent.getY() - play.getY() <= -27)){
					play.setBounds(play.getX(), play.getY() - 57, 55, 55);
				}
				// right
				else if ((mevent.getX() - play.getX() >= 57) &&
					(mevent.getX() - play.getX() <= 112) &&
					(play.getY() <= 341)){
					play.setBounds(play.getX() + 57, play.getY(), 55, 55);
				}
				// left
				else if ((mevent.getX() - play.getX() >= -58) &&
					(mevent.getX() - play.getX() <= -2) &&
					(play.getY() <= 341)){
					play.setBounds(play.getX() - 57, play.getY(), 55, 55);
				}
			}
		}
		
		// 卒吃棋规则
		public void soldierERule(JLabel play, JLabel playTake){
			// right
			if ((playTake.getX() - play.getX() <= 112) &&
				(playTake.getX() - play.getX() >= 57) &&
				(playTake.getY() - play.getY() <= 22) &&
				(playTake.getY() - play.getY() >= -22) &&
				playTake.isVisible() &&
				(getBR(playTake.getName()) != getBR(play.getName()))){
				if ((((getBR(play.getName()) == '1') &&
					(play.getY() >= 284)) ||	// 过河才能向右走
					((getBR(play.getName()) == '2') &&
					(play.getY() <= 341))) &&	// 过河才能向右走
					(getBR(playTake.getName()) != getBR(play.getName()))){
					playTake.setVisible(false);
					play.setBounds(playTake.getX(), playTake.getY(), 55, 55);
				}
			}
			// left
			else if ((playTake.getX() - play.getX() <= -57) &&
				(playTake.getX() - play.getX() >= -112) &&
				(playTake.getY() - play.getY() <= 22) &&
				(playTake.getY() - play.getY() >= -22) &&
				playTake.isVisible() &&
				(getBR(playTake.getName()) != getBR(play.getName()))){
				if ((((getBR(play.getName()) == '1') &&
					(play.getY() >= 284)) ||	// 过河才能向右走
					((getBR(play.getName()) == '2') &&
					(play.getY() <= 341))) &&	// 过河才能向右走
					(getBR(playTake.getName()) != getBR(play.getName()))){	// 此条件可舍弃
					playTake.setVisible(false);
					play.setBounds(playTake.getX(), playTake.getY(), 55, 55);
				}
			}
			// up or down
			else if ((playTake.getX() - play.getX() <= 22) &&
				(playTake.getX() - play.getX() >= -22) &&
				(playTake.getY() - play.getY() <= 112) &&
				(playTake.getY() - play.getY() >= -112) &&
				playTake.isVisible() &&
				(getBR(playTake.getName()) != getBR(play.getName()))){
				if ((((getBR(play.getName()) == '1') &&
					(play.getY() < playTake.getY())) ||	// 黑棋不能向上
					((getBR(play.getName()) == '2') &&
					(play.getY() > playTake.getY()))) &&	// 红棋不能向下
					(getBR(playTake.getName()) != getBR(play.getName()))){
					playTake.setVisible(false);
					play.setBounds(playTake.getX(), playTake.getY(), 55, 55);
				}
			}
			saveCurrentStep(play, Man);
			saveCurrentStep(playTake, i);
		}
		
	}
}
