import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Vector;
import javax.swing.*;

/**
 * 
 * @author WY
 * 主框架类
 */
class ChessMainFrame extends JFrame implements ActionListener, MouseListener, Runnable{
	// 玩家
	JLabel play[] = new JLabel[32];
	// 棋盘
	JLabel image;
	// 窗格
	Container con;
	// 工具栏
	JToolBar jmain;
	// 重新开始
	JButton anew;
	// 悔棋
	JButton repent;
	// 打开
	JButton showOpen;
	// 保存
	JButton showSave;
	// 退出
	JButton exit;
	// 当前信息
	JLabel text;
	// 保存当前操作
	Vector FileVar;
	Vector Var;
	// 规则类对象
	ChessRule rule;
	
	/*
	 * 单击棋子
	 * chessManClick = true 闪烁棋子，并给线程响应
	 * chessManClick = false 吃棋子 停止闪烁 并给线程响应
	 */
	boolean chessManClick;
	/*
	 * 控制玩家走棋
	 * chessPlayClick=1黑棋走棋
	 * chessPlayClick=2红棋走棋  默认红棋
	 * chessPlayClick=3双方都不能走棋
	 */
	int chessPlayClick=2;
	// 控制棋子闪烁的线程
	Thread tmain;
	// 把第一次的单击棋子给线程响应
	static int Man;
	static int i;
	
	ChessMainFrame(){
		new ChessMainFrame("中国象棋");
	}
	
	/*
	 * 构造函数
	 * 初始化图形用户界面
	 */
	ChessMainFrame(String Title){
		// 获行客格引用
		con = this.getContentPane();
		con.setLayout(null);
		// 实例化规则类
		rule = new ChessRule();
		FileVar = new Vector();
		Var = new Vector();
		// 创建工具栏
		jmain = new JToolBar();
		text = new JLabel("欢迎使用中国象棋");
		// 当鼠标放上显示信息
		text.setToolTipText("信息提示");
		anew = new JButton("新游戏");
		anew.setToolTipText("new game");
		exit = new JButton("exit");
		exit.setToolTipText("exit the game");
		showOpen = new JButton("open");
		showOpen.setToolTipText("open old game");
		showSave = new JButton("save");
		showSave.setToolTipText("save current game");
		
		// 把组件添加到工具栏
		jmain.setLayout(new GridLayout(0, 6));
		jmain.add(anew);
		jmain.add(repent);
		jmain.add(showOpen);
		jmain.add(showSave);
		jmain.add(exit);
		jmain.add(text);
		jmain.setBounds(0, 0, 558, 30);
		con.add(jmain);
		// 添加棋子标签
		drawChessMan();
		
		// 注册按钮监听
		anew.addActionListener(this);
		repent.addActionListener(this);
		exit.addActionListener(this);
		showOpen.addActionListener(this);
		showSave.addActionListener(this);
		
		// 注册棋子移动监听
		for (int i = 0; i < 32; i++){
			con.add(play[i]);
			play[i].addMouseListener(this);
		}
		
		// 添加棋盘标签
		con.add(image = new JLabel(new ImageIcon("image\\Main.GIF")));
		image.setBounds(0, 30, 558, 620);
		image.addMouseListener(this);
		
		// 注册窗体关闭监听
		this.addWindowListener(
			new WindowAdapter(){
				public void windowClosing(WindowEvent we){
					System.exit(0);
				}
			}
		);
		
		// 窗体居中
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
		// 设置
		this.setIconImage(new ImageIcon("image红将.GIF").getImage());
		this.setResizable(false);
		this.setTitle(Title);
		this.setSize(558, 670);
		this.show();
	}
	
	/*
	 * 添加棋子方法
	 */
	public void drawChessMan(){
		// 流程控制
		int i;
		int k;
		// 图标
		Icon in;
		// 黑色棋子
		// 车
		in = new ImageIcon("image\黑车.GIF");
		for (i = 0, k = 24; i < 2; i++, k += 456){
			play[i] = new JLabel(in);
			play[i].setBounds(k, 56, 55, 55);
			play[i].setName("车 1");
		}
		// 马
		in = new ImageIcon("image\黑马.GIF");
		for (i = 4, k = 81; i < 6; i++, k += 342){
			play[i] = new JLabel(in);
			play[i].setBounds(k, 56, 55, 55);
			play[i].setName("马 1");
		}
		// 相
		in = new ImageIcon("image\黑象.GIF");
		for (i = 8, k = 138; i < 10; i++, k += 228){
			play[i] = new JLabel(in);
			play[i].setBounds(k, 56, 55, 55);
			play[i].setName("象 1");
		}
		// 士
		in = new ImageIcon("image\黑士.GIF");
		for (i = 12, k = 195; i < 14; i++, k+= 114){
			play[i] = new JLabel(in);
			play[i].setBounds(k, 56, 55, 55);
			play[i].setName("士 1");
		}
		// 卒
		in = new ImageIcon("image\黑卒.GIF");
		for (i = 16, k = 24; i < 21; i++, k += 114){
			play[i] = new JLabel(in);
			play[i].setBounds(k, 227, 55, 55);
			play[i].setName("卒 1" + i);
		}
		// 炮
		in= new ImageIcon("image\黑炮.GIF");
		for (i = 26, k = 81; i < 28; i++, k += 342){
			play[i] = new JLabel(in);
			play[i].setBounds(k, 170, 55, 55);
			play[i].setName("炮 1" + i);
		}
		
		// 将
		in = new ImageIcon("image\黑将.GIF");
		play[30] = new JLabel(in);
		play[30].setBounds(252, 56, 55, 55);
		play[30].setName("将 1");
		
		//////// 红色棋子
		// 车
		in= new ImageIcon("image\红车.GIF");
		for (i = 2, k = 24; i < 4; i++, k += 456){
			paly[i] = new JLabel(in);
			play[i].setBounds(k, 569, 55, 55);
			play[i].setName("车 2");
		}
		// 马
		in = new ImageIcon("image\红马.GIF");
		for (i = 6, k = 81; i < 8; i++, k += 342){
			play[i] = new JLabel(in);
			play[i].setBounds(k, 569, 55, 55);
			paly[i].setName("马 2");
		}
		// 象
		in = new ImagIcon("image\红象.GIF");
		for (i = 10, k = 138; i < 12; i++, k += 228){
			play[i] = new JLabel(in);
			paly[i].setBounds(k, 569, 55, 55);
			play[i].setName("象 2");
		}
		// 士
		in = new ImageIcon("image\红士.GIF");
		for (i = 14, k = 195; i < 16; i++, k += 114){
			play[i] = new JLabel(in);
			play[i].setBounds(k, 569, 55, 55);
			play[i].setName("士 2");
		}
		// 兵
		in = new ImageIcon("image\红兵.GIF");
		for (i = 21, k = 24; i < 26; i++, k+= 114){
			play[i] = new JLabel(in);
			play[i].setBounds(k, 398, 55, 55);
			play[i].setName("兵 2" + i);
		}
		// 炮
		in = new ImageIcon("image\红炮.GIF");
		for (i = 28, k = 81; i < 30; i++, k += 342){
			play[i] = new JLabel(in);
			play[i].setBounds(k, 455, 55, 55);
			play[i].setName("炮 2" + i);
		}
		// 帅
		in = new ImageIcon("image\红帅.GIF");
		play[31] = new JLabel(in);
		paly[31].setBounds(252, 569, 55, 55);
		play[31].setName("帅 2");
	}
	/*
	 * 线程方法控制棋子闪烁
	 */
	public void run(){
		while (true){
			// 单击棋子，第一下开始闪烁
			if (chessManClick){
				play[Man].setVisible(false);
				// time control
				try{
					tmain.sleep(200);
				}
				catch (Exception e){
					
				}
				play[Man].setVisible(true);
			}
			else{	// 闪烁当前提示信息 以免用户看不见
				text.setVisible(false);
				// time control
				try{
					tmain.sleep(250);
				}
				catch (Exception e){
					
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
	/*
	 * 单击棋子的方法
	 */
	public void mouseClicked(MouseEvent mevent){
		System.out.println("Mouse");
		// current coordinate
		int Ex = 0;
		int Ey = 0;
		// start thread
		if (tmain == null){
			tmain = new Thread(this);
			tmain.start();
		}
		// move pieces click the board
		if (mevent.getSource().equals(image)){
			// when red player move
			if (chessPlayClick == 2 && play[Man].getName().charAt(1) == '2'){
				Ex = play[Man].getX();
				Ey = play[Man].getY();
				// move the soldiers
				if (Man > 15 && Man < 26){
					rule.armsRule(Man, play[Man], mevent);
				}
				else if (Man > 25 && Man < 30){	// move pao 
					rule.cannonRule(play[Man], play, mevent);
				}
				else if (Man >= 0 && Man < 4){	// move che
					rule.cannonRule(play[Man], play, mevent);
				}
				else if (Man >= 4 && Man < 8){	// move horse
					rule.horseRule(play[Man], play, mevent);
				}
				else if (Man >= 8 && Man < 12){	// move elephant
					rule.elephantRule(Man, play[Man], play, mevent);
				}
				else if (Man >= 12 && Man < 16){	// move knight
					rule.chapRule(Man, play[Man], play, mevent);
				}
				else if (Man >= 30 && Man < 32){	// move general
					rule.willRule(Man, play[Man], play, mevent);
				}
				
				// 是否走棋错误
				if (Ex == play[Man].getX() && Ey == play[Man].getY()){
					text.setText("please Red move");
					chessPlayClick = 2;
				}
				else{
					text.setText("please Black move");
					chessPlayClick = 1;
				}
			}
			else if (chessPlayClick == 1 && play[Man].getName().charAt(1) == '1'){
				Ex = play[Man].getX();
				Ey = play[Man].getY();
				// move soldiers
				if (Man >= 16 && Man < 26){
					rule.armsRule(Man, play[Man], mevent);
				}
				else if (Man >= 26 && Man < 30){
					rule.cannonRule(play[Man], play, mevent);
				}
				else if (Man >= 0 && Man < 4){
					rule.cannonRule(play[Man], play, mevent);
				}
				else if (Man >= 4 && Man < 8){
					rule.horseRule(play[Man], paly, me);
				}
				else if (Man >= 8 && Man < 12){
					rule.elephantRule(Man, play[Man], play, mevent);
				}
				else if (Man >= 12 && Man < 16){
					rule.chapRule(Man, play[Man], play, mevent);
				}
				else if (Man >= 30 && Man < 32){
					rule.willRule(Man, play[Man], play, mevent);
				}
				
				if (Ex == play[Man].getX() && Ey == play[Man].getY()){
					text.setText("please Black move");
					chessPlayClick = 1;
				}
				else{
					text.setText("please Red move");
					chessPlayClick = 2;
				}
			}
			// 当前没有操作，则停止闪烁
			chessManClick = false;
		}
		else{	// 单击棋子
			if (!chessManClick){	// 第一次单击棋子(闪烁棋子)
				for (int i = 0; i < 32; i++){
					// 被单击的棋子
					if (mevent.getSource().equals(play[i])){
						// 告诉线程，让棋子闪烁
						Man = i;
						// 开始闪烁
						chessManClick = true;
						break;
					}
				}	// for
			} // if
			else if (chessManClick){	// 第二次单击棋子(吃子)
				// 当前无操作，停止闪烁
				chessManClick = false;
				for (i = 0; i < 32; i++){
					// 找到被吃的棋子	红棋吃棋
					if (mevent.getSource().equals(play[i])){
						if (chessPlayClick == 2 && play[Man].getName().charAt(1) == '2'){
							Ex = play[Man].getX();
							Ey = play[Man].getY();
							//兵吃规则
							if (Man >= 16 && Man < 26){
								rule.armsRule(play[Man], play[i]);
							}
							else if (Man >= 26 && Man < 30){
								rule.cannonRule(1, play[Man], play[i], play, mevent);
							}
							else if (Man >= 4 && Man < 8){
								rule.horseRule(play[Man], play[i], play, mevent);
							}
							else if (Man >= 8 && Man < 12){
								rule.elephantRule(play[Man], play[i], play);
							}
							else if (Man >= 12 && Man < 16){
								rule.chapRule(Man, play[Man], play[i], play);
							}
							else if (Man >= 30 && Man < 32){
								rule.willRule(Man, play[Man], play[i], play);
								play[Man].setVisible(true);
							}
							
							// 是否走错棋子，原地未动
							if (Ex == play[Man].getX() && Ey == play[Man].getY()){
								text.setText(" please Red move");
								chessPlayClick = 2;
								break;
							}
							else {
								text.setText(" please Black move");
								chessPlayClick = 1;
								break;
							}
						} // if
						else if (chessPlayClick == 1 && play[Man].getName().charAt(1) == '1'){
							Ex = play[Man].getX();
							Ey = play[Man].getY();
							
							// 吃子规则
							if (Man >= 16 && Man < 26){
								rule.armsRule(play[Man], play[i]);
							}
							else if (Man >= 25 && Man < 30){
								rule.cannonRule(0, play[Man], play[i], play, mevent);
							}
							else if (Man >= 0 && Man < 4){
								rule.cannonRule(1, play[Man], play[i], play, mevent);
							}
							else if (Man >= 4 && Man <8){
								rule.horseRule(play[Man], play[i], play, mevent);
							}
							else if (Man >= 8 && Man < 12){
								rule.elephantRule(play[Man], play[i], play);
							}
							else if (Man >= 12 && Man < 16){
								rule.chapRule(Man, play[Man], play[i], play);
							}
							else if (Man >= 30 && Man < 32){
								rule.willRule(Man, play[Man], play[i], play);
								play[Man].setVisible(true);
							}
							
							if (Ex == play[Man].getX() && Ey == play[Man].getY()){
								text.setText(" please Black move");
								chessPlayClick = 1;
								break;
							}
							else{
								text.setText(" please Red move");
								chessPlayClick = 2;
								break;
							}
						}
					} // if
				} // for
				// is victory or not
				if (!play[31].isVisible()){
					JOptionPane.showConfirmDialog(
						this, "Black win", "first player win the game",
						JOptionPane.DEFAULT_OPTION, JOptionPane.WARNING_MESSAGE
					);
					// 双方都不能走棋了
					chessPlayClick = 3;
					text.setText(" Black win the game");
				}
				else if (!play[30].isVisible()){
					JOptionPane.showConfirmDialog(
						this, "Red win", "second player win the game",
						JOptionPane.DEFAULT_OPTION, JOptionPane.WARNING_MESSAGE
					);
					chessPlayClick = 3;
					text.setText(" red win the game");
				}
			} // else
		} // else
	}
	
	public void mousePressed(MouseEvent mevent){
		
	}
	
	public void mouseReleased(MouseEvent mevent){
		
	}
	
	public void mouseEntered(MouseEvent mevent){
		
	}
	
	public void mouseExited(MouseEvent mevent){
		
	}
	
	/*
	 * 定义按钮事件响应
	 */
	public void actionPerformed(ActionEvent aevent){
		// restart button
		if (aevent.getSource().equals(anew)){
			int i;
			int k;
			// 重新排列棋子
			/* black */
			// 车
			for (i = 0, k = 24; i < 2; i++, k += 456){
				play[i].setBounds(k, 56, 55, 55);
			}
			for (i = 4, k = 81; i < 6; i++, k += 342){
				play[i].setBounds(k, 56, 55, 55);
			}
			for (i = 8, k = 138; i < 10; i++, k += 228){
				play[i].setBounds(k, 56, 55, 55);
			}
			for (i = 12, k = 195; i < 14; i++, k += 114){
				play[i].setBounds(k, 56, 55, 55);
			}
			for (i = 16, k = 24; i < 21; i++, k += 114){
				play[i].setBounds(k, 227, 55, 55);
			}
			for (i = 26, k = 81; i < 28; i++, k += 342){
				play[i].setBounds(k, 170, 55, 55);
			}
			play[30].setBounds(252, 56, 55, 55);
			
			/* red */
			for (i = 2, k = 24; i < 4; k += 456){
				play[i].setBounds(k, 569, 55, 55);
			}
			for (i = 6, k = 81; i < 8; i++, k += 342){
				play[i].setBounds(k, 569, 55, 55);
			}
			for (i = 10, k = 138; i < 12; i++, k += 228){
				play[i].setBounds(k, 569, 55, 55);
			}
			for (i = 14, k = 195; i < 16; i++, k += 114){
				play[i].setBounds(k, 569, 55, 55);
			}
			for (i = 21, k = 24; i < 26; i++, k += 114){
				play[i].setBounds(k, 398, 55, 55);
			}
			for (i = 28, k = 81; i < 30; i++, k += 342){
				play[i].setBounds(k, 455, 55, 55);
			}
			play[31].setBounds(252, 569, 55, 55);
			
			chessPlayClick = 2;
			text.setText(" please Red move");
			for (i = 0; i < 32; i++){
				play[i].setVisible(true);
			}
			Var.clear();	// 清楚vector中的内容
		}
		else if (aevent.getSource().equals(repent)){	// 悔棋
			try{
				// 获得setVisible属性值
				String str = (String)Var.get(Var.size() - 4);
				int x = Integer.parseInt((String)Var.get(Var.size() - 3));
				int y = Integer.parseInt((String)Var.get(Var.size() - 2));
				int index = Integer.parseInt((String)Var.get(Var.size() - 1));
				// 赋给棋子
				play[index].setVisible(true);
				play[index].setBounds(x, y, 55, 55);
				if (play[index].getName().charAt(1) == '1'){
					text.setText(" please Black move");
					chessPlayClick = 1;
				}
				else{
					text.setText(" please Red move");
					chessPlayClick = 2;
				}
				// 删除使用过的坐标
				Var.remove(Var.size()-4);
				Var.remove(Var.size()-3);
				Var.remove(Var.size()-2);
				Var.remove(Var.size()-1);
				
				// 停止棋子闪烁
				chessManClick = false;
			}
			catch (Exception e){
				
			}
		}
		else if (aevent.getSource().equals(showOpen)){	// 打开棋局
			try{
				// 打开对话框
				JFileChooser jfcOpen = new JFileChooser("打开棋局");
				int v = jfcOpen.showOpenDialog(this);
				if (v != JFileChooser.CANCEL_OPTION){
					// 删除集合所有信息
					Var.removeAllElements();
					FileVar.removeAllElements();
					// 打开文件获得所有数据
					FileInputStream fileIn = new FileInputStream(jfcOpen.getSelectedFile());
					ObjectInputStream objIn = new ObjectInputStream(fileIn);
					FileVar = (Vector)objIn.readObject();
					fileIn.close();
					objIn.close();
					// 集合内容对应棋子坐标
					int k = 0;
					for (int i = 0; i < 32; i++){
						play[i].setBounds(((Integer)FileVar.get(k)).intValue(), ((Integer)FileVar.get(k + 1)).intValue(), 55, 55);
						// 被吃掉的棋子不显示
						if (!((boolean)FileVar.elementAt(k + 2)).booleanValue()){
							play[i].setVisible(false);
						}
						k += 3;
					}
					// 当前该哪方棋子走棋
					if (((String)FileVar.lastElement()).toString().equals(" please Red move")){
						text.setText(((String)FileVar.lastElement()).toString());
						chessPlayClick = 2;
					}
					else if (((String)FileVar.lastElement()).toString().equals(" please Black move")){
						text.setText(((String)FileVar.lastElement()).toString());
						chessPlayClick = 1;
					}
					else if (((String)FileVar.lastElement()).toString().substring(5).equals("利")){
						text.setText(((String)FileVar.lastElement()).toString());
						chessPlayClick = 3;
					}
				}
			}
			catch (Exception e){
				System.out.println("Error ShowOpen");
			}
		}
		else if (aevent.getSource().equals(showSave)){	// 保存当前棋局
			try{
				// 保存对话框
				JFileChooser jfcSave = new JFileChooser("save current chess environment");
				int v = jfcSave.showSaveDialog(this);
				if (v != JFileChooser.CANCEL_OPTION){
					FileVar.removeAllElements();
					// 保存所有棋子的坐标即可见性
					for (int i = 0; i < 32; i++){
						FileVar.addElement(new Integer(play[i].getX()));
						FileVar.addElement(new Integer(play[i].getY()));
						FileVar.addElement(new Boolean(play[i].isVisible()));
					}
					// 保存当前该哪方吃棋
					FileVar.add(text.getText());
					// 保存到文件
					FileOutputStream fileOut = new FileOutputStream(jfcSave.getSelectedFile());
					ObjectOutputStream objOut = new ObjectOutputStream(fileOut);
					objOut.writeObject(FileVar);
					objOut.close();
					fileOut.close();
				}
			}
			catch (Exception e){
				System.out.println("Error ShowSave");
			}
		}
		else if (aevent.getSource().equals(exit)){	// 退出
			int j = JOptionPane.showConfirmDialog(
				this, "is really exited?", "exit",
				JOptionPane.YES_OPTION, JOptionPane.QUESTION_MESSAGE
			);
			if (j == JOptionPane.YES_OPTION){
				System.exit(0);
			}
		}
	}
}

