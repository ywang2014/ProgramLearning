import java.awt.event.MouseEvent;

import javax.swing.JLabel;

/**
 * 
 * @author WY
 * 中国象棋规则类
 */
class ChessRule{
	// 车的移动规则，炮的移动规则
	public void cannonRule(JLabel play, JLabel playA[], MouseEvent mevent){
		int count = 0;
		// 上下移动
		if (play.getX() - mevent.getX() <= 0 && play.getX() - mevent.getX() >= -55){
			for (int i = 56; i <= 571; i += 57){
				// 移动y坐标，是否有指定坐标相近的
				if ((i - mevent.getY() >= -27) && (i - mevent.getY() <= 27)){
					// 所有的棋子
					for (int j = 0; j < 32; j++){
						if ((playA[j].getX() - play.getX() >= -27) &&
							(playA[j].getX() - play.getX() <= 27) &&
							(playA[j].getName() != play.getName()) &&
							playA[j].isVisible()){
								// 从起点到终点(从左到右)
							for (int k = play.getY() + 57; k < i; k += 57){
								// 大于起点，小于终点的坐标，就可以知道中间是否有棋子
								if (playA[j].getY() < i && playA[j].getY() > play.getY()){
									count++;
									break;
								}
							}// for
							// 从起点到终点(从右到左)
							for (int k = i + 57; k < play.getY(); k += 57){
								if (playA[j].getY() < play.getY() && playA[j].getY() > i){
									count++;
									break;
								}
							}
						}// if
					}// for
					// 起点和终点没有棋子就可以移动了
					if (count == 0){
						Var.add(String.valueOf(play.isVisible()));
						Var.add(String.valueOf(play.getX()));
						Var.add(String.valueOf(play.getY()));
						Var.add(String.valueOf(Man));
						play.setBounds(play.getX(), i, 55, 55);
						break;
					}
				}// if
			}// for
		}// if
		// 左右移动
		else if ((play.getY()-mevent.getY() >= -27) &&
			(play.getY() - mevent.getY() <= 27)){
			// 指定所有模糊X坐标
			for (int i = 24; i <= 480; i += 57){
				if ((i - mevent.getX() >= -55) && (i - mevent.getX() <= 0)){
					for (int j = 0; j < 32; j++){
						// 找出一条横线上的所有棋子，不包括自己
						if ((playA[j].getY() - play.getY() >= -27) &&
							(playA[j].getY() - play.getY() <= 27) &&
							(playA[j].getName() != play.getName()) &&
							playA[j].isVisible()){
							// 从起点到终点 从上到下
							for (int k = play.getX() + 57; k < i; k += 57){
								if (playA[j].getX() < i && playA[j].getX() > play.getX()){
									count++;
									break;
								}
							}
							// 从起点到终点 从下到上
							for (int k = i + 57; k < play.getX(); k += 57){
								if (playA[j].getX() < play.getX() && playA[j].getX() > i){
									count++;
									break;
								}
							}
						} // if
					} // for
					if (count == 0){
						Var.add(String.valueOf(play.isVisible()));
						Var.add(String.valueOf(play.getX()));
						Var.add(String.valueOf(play.getY()));
						Var.add(String.valueOf(Man));
						play.setBounds(i, play.getY(), 55, 55);
						break;
					}
				} // if
			} // for
		} // else
	} 
	
	// 车、炮吃子的规则
	public void cannonRule(int Chess, JLabel play, JLabel playTake, JLabel playA[], MouseEvent mevent){
		int count = 0;	// 起点终点间是否有棋子
		for (int j = 0; j < 32; j++){
			if ((playA[j].getX() - play.getX() >= -27) && 
				(playA[j].getX() - play.getX() <= 27) &&
				(playA[j].getName() != play.getName()) &&
				playA[j].isVisible()){
				// 从上到下
				for (int k = play.getY() + 57; k < playTake.getY(); k += 57){
					if (playA[j].getY() < playTake.getY() && (playA[j].getY() > play.getY())){
						// 计算起点和终点间的棋子个数
						count++;
						break;
					}
				}
				// from bottom to top
				for (int k = playTake.getY(); k < play.getY(); k += 57){
					if (playA[j].getY() < play.getY() && (playA[j].getY() > playTake.getY())){
						count++;
						break;
					}
				}
			}
			else if (playA[j].getY() - play.getY() >= -10 &&
				(playA[j].getY() - play.getY() <= 10) &&
				(playA[j].getName() != play.getName()) &&
				playA[j].isVisible()){
				for (int k = play.getX() + 50; k < playTake.getX(); k += 57){
					if (playA[j].getX() < playTake.getX() && playA[j].getX() > play.getX()){
						count++;
						break;
					}
				}
				for (int k = playTake.getX(); k < play.getX(); k += 57){
					if (playA[i].getX() < play.getX() && playA[j].getX() > playTake.getX()){
						count++;
						break;
					}
				}
			}
		} // for
		if (count == 1 && Chess == 0 && playTake.getName().charAt(1) != play.getName().charAt(1)){
			Var.add(String.valueOf(play.isVisible()));
			Var.add(String.valueOf(play.getX()));
			Var.add(String.valueOf(play.getY()));
			Var.add(String.valueOf(Man));
			
			Var.add(String.valueOf(playTake.getY()));
			Var.add(String.valueOf(i));
			
			playTake.setVisible(false);
			play.setBounds(playTake.getX(), playTake.getY(), 55, 55);
		}
		else if (count == 0 && Chess == 1 && playTake.getName().charAt(1) != play.getName().charAt(1)){
			Var.add(String.valueOf(play.isVisible()));
			Var.add(String.valueOf(play.getX()));
			Var.add(String.valueOf(play.getY()));
			Var.add(String.valueOf(play.Man));
			
			Var.add(String.valueOf(playTake.isVisible()));
			Var.add(String.valueOf(playTake.getX()));
			Var.add(String.valueOf(playTake.getY()));
			Var.add(String.valueOf(i));
			
			playTake.setVisible(false);
			play.setBounds(playTake.getX(), playTake.getY(), 55, 55);
		}
	}
	
	// 马的移动规则
	public void horseRule(JLabel play, JLabel playA[], MouseEvent mevent){
		// 保存坐标和障碍  57页
		int Ex = 0;
		int Ey = 0;
		int Move = 0;
		
		// 上移、左边
		if (play.getX() - mevent.getX() >= 2 && 
			play.getX() <= 57 &&
			play.getY() - mevent.getY() >= 87 &&
			play.getY() - mevent.getY() <= 141){
			// 合法的y坐标
			for (int i = 56; i <= 571; i += 57){
				// 移动y坐标，是否有指定坐标相近的
				if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
					Ey = i;
					break;
				}
			}
			// 合法的x坐标
			for (int i = 24; i <= 480; i += 57){
				// 移动x坐标，是否有指定坐标相近的
				if (i - mevent.getX() >= -55 && i - mevent.getX() <= 0){
					Ex = i;
					break;
				}
			}
			// 正前方是否有别的棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getX() - playA[i].getX() == 0) &&
					(play.getY() - playA[i].getY() == 57)){
					Move = 1;
					break;
				}
			}
			// 可以移动该棋子
			if (Move == 0){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(play.Man));
				
				play.setBounds(Ex, Ey, 55, 55);
			}
		} //if
		// 左移、上边
		else if (play.getY() - mevent.getY() >= 27 && 
			play.getY() - mevent.getY() <= 86 &&
			(play.getX() - mevent.getX() >= 70) &&
			(play.getX() - mevent.getX() <= 130)){
			// Y
			for (int i = 56; i <= 571; i += 57){
				if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
					Ey = i;
					break;
				}
			}
			// X
			for (int i = 24; i <= 480; i += 57){
				if (i - mevent.getX() >= -55 && i - mevent.getX() <= 0){
					Ex = i;
					break;
				}
			}
			// 正左方是否有别的棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getY() - playA[i].getY() == 0) &&
					(play.getX() - playA[i].getX() == 57)){
					Move = 1;
					break;
				}
			}
			if (Move == 0){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(play.Man));
				
				play.setBounds(Ex, Ey, 55, 55);
			}
		} // else
		// 下移、右边
		else if (play.getY() - mevent.getY() >= -141 && 
			play.getY() - mevent.getY() <= -87 &&
			(play.getX() - mevent.getX() >= -87) &&
			(play.getX() - mevent.getX() <= -2)){
			// Y
			for (int i = 56; i <= 571; i += 57){
				if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
					Ey = i;
					break;
				}
			}
			// X
			for (int i = 24; i <= 480; i += 57){
				if (i - mevent.getX() >= -55 && i - mevent.getX() <= 0){
					Ex = i;
					break;
				}
			}
			// 正下方是否有别的棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getY() - playA[i].getY() == 0) &&
					(play.getX() - playA[i].getX() == -57)){
					Move = 1;
					break;
				}
			}
			if (Move == 0){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(play.Man));
				
				play.setBounds(Ex, Ey, 55, 55);
			}
		} // else
		// 上移、右边
		else if (play.getY() - mevent.getY() >= 87 && 
			play.getY() - mevent.getY() <= 141 &&
			(play.getX() - mevent.getX() >= -87) &&
			(play.getX() - mevent.getX() <= -30)){
			// Y
			for (int i = 56; i <= 571; i += 57){
				if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
					Ey = i;
					break;
				}
			}
			// X
			for (int i = 24; i <= 480; i += 57){
				if (i - mevent.getX() >= -55 && i - mevent.getX() <= 0){
					Ex = i;
					break;
				}
			}
			// 正左方是否有别的棋子
			for (int i = 0; i < 32; i++){
				// System.out.println(i + "playA[i].getX()=" + playA[i].getX());
				if (playA[i].isVisible() &&
					(play.getX() - playA[i].getX() == 0) &&
					(play.getY() - playA[i].getY() == 57)){
					Move = 1;
					break;
				}
			}
			if (Move == 0){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(play.Man));
				
				play.setBounds(Ex, Ey, 55, 55);
			}
		} // else
		// 下移、左边
		else if (play.getY() - mevent.getY() >= -141 && 
			play.getY() - mevent.getY() <= -87 &&
			(play.getX() - mevent.getX() >= 10) &&
			(play.getX() - mevent.getX() <= 87)){
			// Y
			for (int i = 56; i <= 571; i += 57){
				if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
					Ey = i;
					break;
				}
			}
			// X
			for (int i = 24; i <= 480; i += 57){
				if (i - mevent.getX() >= -55 && i - mevent.getX() <= 0){
					Ex = i;
					break;
				}
			}
			// 正下方是否有别的棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getX() - playA[i].getX() == 0) &&
					(play.getY() - playA[i].getY() == 57)){
					Move = 1;
					break;
				}
			}
			if (Move == 0){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(play.Man));
				
				play.setBounds(Ex, Ey, 55, 55);
			}
		} // else
		// 右移、上边
		else if (play.getY() - mevent.getY() >= 30 && 
			play.getY() - mevent.getY() <= 87 &&
			(play.getX() - mevent.getX() >= -141) &&
			(play.getX() - mevent.getX() <= -87)){
			// Y
			for (int i = 56; i <= 571; i += 57){
				if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
					Ey = i;
					break;
				}
			}
			// X
			for (int i = 24; i <= 480; i += 57){
				if (i - mevent.getX() >= -55 && i - mevent.getX() <= 0){
					Ex = i;
					break;
				}
			}
			// 正右方是否有别的棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getY() - playA[i].getY() == 0) &&
					(play.getX() - playA[i].getX() == 57)){
					Move = 1;
					break;
				}
			}
			if (Move == 0){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(play.Man));
				
				play.setBounds(Ex, Ey, 55, 55);
			}
		} // else
		// 右移、下边
		else if (play.getY() - mevent.getY() >= -87 && 
			play.getY() - mevent.getY() <= -30 &&
			(play.getX() - mevent.getX() >= -141) &&
			(play.getX() - mevent.getX() <= -87)){
			// Y
			for (int i = 56; i <= 571; i += 57){
				if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
					Ey = i;
					break;
				}
			}
			// X
			for (int i = 24; i <= 480; i += 57){
				if (i - mevent.getX() >= -55 && i - mevent.getX() <= 0){
					Ex = i;
					break;
				}
			}
			// 正左方是否有别的棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getY() - playA[i].getY() == 0) &&
					(play.getX() - playA[i].getX() == 57)){
					Move = 1;
					break;
				}
			}
			if (Move == 0){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(play.Man));
				
				play.setBounds(Ex, Ey, 55, 55);
			}
		} // else
		// 左移、下边
		else if (play.getY() - mevent.getY() >= -87 && 
			play.getY() - mevent.getY() <= -30 &&
			(play.getX() - mevent.getX() >= 87) &&
			(play.getX() - mevent.getX() <= 141)){
			// Y
			for (int i = 56; i <= 571; i += 57){
				if (i - mevent.getY() >= -27 && i - mevent.getY() <= 27){
					Ey = i;
					break;
				}
			}
			// X
			for (int i = 24; i <= 480; i += 57){
				if (i - mevent.getX() >= -55 && i - mevent.getX() <= 0){
					Ex = i;
					break;
				}
			}
			// 正左方是否有别的棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getY() - playA[i].getY() == 0) &&
					(play.getX() - playA[i].getX() == 57)){
					Move = 1;
					break;
				}
			}
			if (Move == 0){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(play.Man));
				
				play.setBounds(Ex, Ey, 55, 55);
			}
		} // else
	}
	
	// 马吃棋规则
	public void horseRule(JLabel play, JLabel playTake, JLabel playA[], MouseEvent mevent){
		int Move = 0;	// 障碍
		boolean Chess = false;
		// 上移、左吃
		if (play.getName().charAt(1) != playTake.getName().charAt(1) &&
			(play.getX() - playTake.getX() == 57) &&
			(play.getY() - playTake.getY() == 114)){
			// 正前方是否有别的棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getX() - playA[i].getX() == 0) &&
					(play.getY() - playA[i].getY() == 57)){
					Move = 1;
					break;
				}
			}
			Chess = true;
		} // if
		// 上移、右吃
		else if (play.getName().charAt(1) != playTake.getName().charAt(1) &&
			(play.getX() - playTake.getX() == -57) &&
			(play.getY() - playTake.getY() == 114)){
			// 正前方是否有别的棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getX() - playA[i].getX() == 0) &&
					(play.getY() - playA[i].getY() == 57)){
					Move = 1;
					break;
				}
			}
			Chess = true;
		} // else if
		// 左移、上吃
		else if (play.getName().charAt(1) != playTake.getName().charAt(1) &&
			(play.getX() - playTake.getX() == 114) &&
			(play.getY() - playTake.getY() == 57)){
			// 正左方是否有别的棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getX() - playA[i].getX() == 57) &&
					(play.getY() - playA[i].getY() == 0)){
					Move = 1;
					break;
				}
			}
			Chess = true;
		} // else if
		// 左移、下吃
		else if (play.getName().charAt(1) != playTake.getName().charAt(1) &&
			(play.getX() - playTake.getX() == 114) &&
			(play.getY() - playTake.getY() == -57)){
			// 正左方是否有别的棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getX() - playA[i].getX() == 57) &&
					(play.getY() - playA[i].getY() == 0)){
					Move = 1;
					break;
				}
			}
			Chess = true;
		} // else if
		// 右移、上吃
		else if (play.getName().charAt(1) != playTake.getName().charAt(1) &&
			(play.getX() - playTake.getX() == -114) &&
			(play.getY() - playTake.getY() == 57)){
			// 正右方是否有别的棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getX() - playA[i].getX() == -57) &&
					(play.getY() - playA[i].getY() == 0)){
					Move = 1;
					break;
				}
			}
			Chess = true;
		} // else if
		// 右移、下吃
		else if (play.getName().charAt(1) != playTake.getName().charAt(1) &&
			(play.getX() - playTake.getX() == -114) &&
			(play.getY() - playTake.getY() == -57)){
			// 正右方是否有别的棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getX() - playA[i].getX() == -57) &&
					(play.getY() - playA[i].getY() == 0)){
					Move = 1;
					break;
				}
			}
			Chess = true;
		} // else if
		// 下移、左吃
		else if (play.getName().charAt(1) != playTake.getName().charAt(1) &&
			(play.getX() - playTake.getX() == 57) &&
			(play.getY() - playTake.getY() == -114)){
			// 正下方是否有别的棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getX() - playA[i].getX() == 0) &&
					(play.getY() - playA[i].getY() == -57)){
					Move = 1;
					break;
				}
			}
			Chess = true;
		} // else if
		// 下移、右吃
		else if (play.getName().charAt(1) != playTake.getName().charAt(1) &&
			(play.getX() - playTake.getX() == -57) &&
			(play.getY() - playTake.getY() == -114)){
			// 正下方是否有别的棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getX() - playA[i].getX() == 0) &&
					(play.getY() - playA[i].getY() == 57)){
					Move = 1;
					break;
				}
			}
			Chess = true;
		} // else if
		
		// 没有障碍，可以吃棋
		if (Chess && Move == 0 && playTake.getName().charAt(1) != play.getName().charAt(1)){
			Var.add(String.valueOf(play.isVisible()));
			Var.add(String.valueOf(play.getX()));
			Var.add(String.valueOf(play.getY()));
			Var.add(String.valueOf(Man));
			
			Var.add(String.valueOf(playTake.isVisible()));
			Var.add(String.valueOf(playTake.getX()));
			Var.add(String.valueOf(playTake.getY()));
			Var.add(String.valueOf(i));
			
			playTake.setVisible(false);
			play.setBounds(playTake.getX(), playTake.getY(), 55, 55);
		}
	}
	// 象的移动规则
	public void elephantRule(int Man, JLabel play, JLabel playA[], MouseEvent mevent){
		int Ex = 0;
		int Ey = 0;
		int Move = 0;
		// 上左
		if (play.getX() - mevent.getX() <= 141 &&
			(play.getX() - mevent.getX() >= 87) &&
			(play.getY() - mevent.getY() <= 141) &&
			(play.getY() - mevent.getY() >= 87)){
			// Y 合法坐标
			for (int i = 56; i < 571; i += 57){
				if ((i - mevent.getY() >= -27) && (i - mevent.getY() <= 27)){
					Ey = i;
					break;
				}
			}
			// X 合法坐标
			for (int i = 24; i <= 480; i += 57){
				if ((i - mevent.getX() >= -27) && (i - mevent.getX() <= 27)){
					Ex = i;
					break;
				}
			}
			// 左上方是否有棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() && 
					(play.getX() - playA[i].getX() == 57) &&
					(play.getY() - playA[i].getY() == 57)){
					Move = 1;
					break;
				}
			}
			// 红棋不能过楚河汉界
			if (Move == 0 && Ey >= 341 && Man > 9){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				// System.out.println("Ex = " + Ex);
				// System.out.println("Ey = " + Ey);
				
				play.setBounds(Ex, Ey, 55, 55);
			}
			// 黑棋不能过楚河汉界
			else if (Move == 0 && Ey <= 284 && Man < 10){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				
				play.setBounds(Ex, Ey, 55, 55);
			}
		} // if
		// 上右
		else if (play.getX() - mevent.getX() <= -87 &&
			(play.getX() - mevent.getX() >= -141) &&
			(play.getY() - mevent.getY() <= 141) &&
			(play.getY() - mevent.getY() >= 87)){
			// Y 合法坐标
			for (int i = 56; i < 571; i += 57){
				if ((i - mevent.getY() >= -27) && (i - mevent.getY() <= 27)){
					Ey = i;
					break;
				}
			}
			// X 合法坐标
			for (int i = 24; i <= 480; i += 57){
				if ((i - mevent.getX() >= -27) && (i - mevent.getX() <= 27)){
					Ex = i;
					break;
				}
			}
			// 右上方是否有棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() && 
					(play.getX() - playA[i].getX() == -57) &&
					(play.getY() - playA[i].getY() == 57)){
					Move = 1;
					break;
				}
			}
			// 红棋不能过楚河汉界
			if (Move == 0 && Ey >= 341 && Man > 9){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				// System.out.println("Ex = " + Ex);
				// System.out.println("Ey = " + Ey);
				
				play.setBounds(Ex, Ey, 55, 55);
			}
			// 黑棋不能过楚河汉界
			else if (Move == 0 && Ey <= 284 && Man < 10){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				
				play.setBounds(Ex, Ey, 55, 55);
			}
		} // else if
		// 下左
		else if (play.getX() - mevent.getX() <= 141 &&
			(play.getX() - mevent.getX() >= 87) &&
			(play.getY() - mevent.getY() <= -87) &&
			(play.getY() - mevent.getY() >= -141)){
			// Y 合法坐标
			for (int i = 56; i < 571; i += 57){
				if ((i - mevent.getY() >= -27) && (i - mevent.getY() <= 27)){
					Ey = i;
					break;
				}
			}
			// X 合法坐标
			for (int i = 24; i <= 480; i += 57){
				if ((i - mevent.getX() >= -27) && (i - mevent.getX() <= 27)){
					Ex = i;
					break;
				}
			}
			// 下左方是否有棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() && 
					(play.getX() - playA[i].getX() == 57) &&
					(play.getY() - playA[i].getY() == -57)){
					Move = 1;
					break;
				}
			}
			// 红棋不能过楚河汉界
			if (Move == 0 && Ey >= 341 && Man > 9){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				
				play.setBounds(Ex, Ey, 55, 55);
			}
			// 黑棋不能过楚河汉界
			else if (Move == 0 && Ey <= 284 && Man < 10){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				
				play.setBounds(Ex, Ey, 55, 55);
			}
		} // else if
		// 下右
		else if (play.getX() - mevent.getX() <= -87 &&
			(play.getX() - mevent.getX() >= -141) &&
			(play.getY() - mevent.getY() <= -87) &&
			(play.getY() - mevent.getY() >= -141)){
			// Y 合法坐标
			for (int i = 56; i < 571; i += 57){
				if ((i - mevent.getY() >= -27) && (i - mevent.getY() <= 27)){
					Ey = i;
					break;
				}
			}
			// X 合法坐标
			for (int i = 24; i <= 480; i += 57){
				if ((i - mevent.getX() >= -27) && (i - mevent.getX() <= 27)){
					Ex = i;
					break;
				}
			}
			// 下右方是否有棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() && 
					(play.getX() - playA[i].getX() == -57) &&
					(play.getY() - playA[i].getY() == -57)){
					Move = 1;
					break;
				}
			}
			// 红棋不能过楚河汉界
			if (Move == 0 && Ey >= 341 && Man > 9){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				// System.out.println("Ex = " + Ex);
				// System.out.println("Ey = " + Ey);
				
				play.setBounds(Ex, Ey, 55, 55);
			}
			// 黑棋不能过楚河汉界
			else if (Move == 0 && Ey <= 284 && Man < 10){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				
				play.setBounds(Ex, Ey, 55, 55);
			}
		} // else if
	}
	
	// 象吃棋规则
	public void elephantRule(JLabel play, JLabel playTake, JLabel playA[]){
		int Move = 0;
		boolean Chess = false;
		// 吃左上方的棋子
		if (play.getX() - playTake.getX() >= 87 && 
			(play.getX() - playTake.getX() <= 141) && 
			(play.getY() - playTake.getY() >= 87) &&
			(play.getY() - playTake.getY() <= 141)){
			// 左上方是否有棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getX() - playA[i].getX() == 57) &&
					(play.getY() - playA[i].getY() == 57)){
					Move = 1;
					break;
				}
			}
			Chess = true;
		}
		// 吃右上方的棋子
		else if (play.getX() - playTake.getX() >= -141 && 
			(play.getX() - playTake.getX() <= -87) && 
			(play.getY() - playTake.getY() >= 87) &&
			(play.getY() - playTake.getY() <= 141)){
			// 右上方是否有棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getX() - playA[i].getX() == -57) &&
					(play.getY() - playA[i].getY() == 57)){
					Move = 1;
					break;
				}
			}
			Chess = true;
		}
		// 吃下左方的棋子
		else if (play.getX() - playTake.getX() >= 87 && 
			(play.getX() - playTake.getX() <= 141) && 
			(play.getY() - playTake.getY() >= -141) &&
			(play.getY() - playTake.getY() <= -87)){
			// 下左方是否有棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getX() - playA[i].getX() == 57) &&
					(play.getY() - playA[i].getY() == -57)){
					Move = 1;
					break;
				}
			}
			Chess = true;
		}
		// 吃下右方的棋子
		else if (play.getX() - playTake.getX() >= -141 && 
			(play.getX() - playTake.getX() <= -87) && 
			(play.getY() - playTake.getY() >= -141) &&
			(play.getY() - playTake.getY() <= -87)){
			//下右方是否有棋子
			for (int i = 0; i < 32; i++){
				if (playA[i].isVisible() &&
					(play.getX() - playA[i].getX() == -57) &&
					(play.getY() - playA[i].getY() == -57)){
					Move = 1;
					break;
				}
			}
			Chess = true;
		}
		// 无障碍，且不能吃自己的棋子
		if (Chess && Move == 0 && playTake.getName().charAt(1) != play.getName().charAt(1)){
			Var.add(String.valueOf(play.isVisible()));
			Var.add(String.valueOf(play.getX()));
			Var.add(String.valueOf(play.getY()));
			Var.add(String.valueOf(Man));
			
			Var.add(String.valueOf(playTake.isVisible()));
			Var.add(String.valueOf(playTake.getX()));
			Var.add(String.valueOf(playTake.getY()));
			Var.add(String.valueOf(i));
			
			playTake.setVisible(false);
			play.setBounds(playTake.getX(), playTake.getY(), 55, 55);
			
		}
	}
	
	// 士的移动规则
	public void chapRule(int Man, JLabel play, JLabel playA[], MouseEvent mevent){
		// up right
		if (mevent.getX() - play.getX() >= 29 &&
			(mevent.getX() - play.getX() <= 114) &&
			(mevent.getY() - play.getY() >= -90) &&
			(mevent.getY() - play.getY() <= -25)){
			// 士不能超过自己的界限
			if (Man < 14 &&
				(play.getX() + 57 >= 195) &&
				(play.getX() + 57 <= 309) &&
				(play.getY() - 57 <= 170)){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				
				play.setBounds(play.getX() + 57, play.getY() - 57, 55, 55);
			}
			// 士不能超过自己的界限
			if (Man > 13 &&
				(play.getX() + 57 >= 195) &&
				(play.getX() + 57 <= 309) &&
				(play.getY() - 57 >= 455)){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				
				play.setBounds(play.getX() + 57, play.getY() - 57, 55, 55);
			}
		} // else if
		// up left
		else if (mevent.getX() - play.getX() >= -114 &&
			(mevent.getX() - play.getX() <= -25) &&
			(mevent.getY() - play.getY() >= -95) &&
			(mevent.getY() - play.getY() <= -20)){
			// 士不能超过自己的界限
			if (Man < 14 &&
				(play.getX() - 57 >= 195) &&
				(play.getX() - 57 <= 309) &&
				(play.getY() - 57 <= 170)){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				
				play.setBounds(play.getX() - 57, play.getY() - 57, 55, 55);
			}
			// 士不能超过自己的界限
			if (Man > 13 &&
				(play.getX() - 57 >= 195) &&
				(play.getX() - 57 <= 309) &&
				(play.getY() - 57 >= 455)){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				
				play.setBounds(play.getX() + 57, play.getY() - 57, 55, 55);
			}
		} // else if
		// down left
		else if (mevent.getX() - play.getX() >= -114 &&
			(mevent.getX() - play.getX() <= -20) &&
			(mevent.getY() - play.getY() >= 2) &&
			(mevent.getY() - play.getY() <= 87)){
			// 士不能超过自己的界限
			if (Man < 14 &&
				(play.getX() - 57 >= 195) &&
				(play.getX() - 57 <= 309) &&
				(play.getY() + 57 <= 170)){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				
				play.setBounds(play.getX() - 57, play.getY() + 57, 55, 55);
			}
			// 士不能超过自己的界限
			if (Man > 13 &&
				(play.getX() - 57 >= 195) &&
				(play.getX() - 57 <= 309) &&
				(play.getY() + 57 >= 455)){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				
				play.setBounds(play.getX() - 57, play.getY() + 57, 55, 55);
			}
		} // else if
		// down right
		else if (mevent.getX() - play.getX() >= 27 &&
			(mevent.getX() - play.getX() <= 114) &&
			(mevent.getY() - play.getY() >= 2) &&
			(mevent.getY() - play.getY() <= 87)){
			// 士不能超过自己的界限
			if (Man < 14 &&
				(play.getX() + 57 >= 195) &&
				(play.getX() + 57 <= 309) &&
				(play.getY() + 57 <= 170)){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				
				play.setBounds(play.getX() + 57, play.getY() + 57, 55, 55);
			}
			// 士不能超过自己的界限
			if (Man > 13 &&
				(play.getX() + 57 >= 195) &&
				(play.getX() + 57 <= 309) &&
				(play.getY() + 57 >= 455)){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				
				play.setBounds(play.getX() + 57, play.getY() + 57, 55, 55);
			}
		} // else if
	}
	
	// 士吃棋规则
	public void chapRule(int Man, JLabel play, JLabel playTake, JLabel playA[]){
		boolean Chap = false;
		// up right
		if ((play.getX() - playTake.getX() <= -20) &&
			(play.getX() - playTake.getX() >= -114) &&
			(play.getY() - playTake.getY() <= 87) &&
			(play.getY() - playTake.getY() >= 2)){
			if (Man < 14 &&
				(playTake.getX() >= 195) &&
				(playTake.getX() <= 309) &&
				(playTake.getY() <= 170) &&
				(playTake.isVisible())){
				Chap = true;
			}
			else if (Man > 13 &&
				(playTake.getX() >= 195) &&
				(playTake.getX() <= 309) &&
				(playTake.getY() >= 455) &&
				playTake.isVisible()){
				Chap = true;
			}
		}
		// up left
		else if ((play.getX() - playTake.getX() <= 114) &&
			(play.getX() - playTake.getX() >= 25) &&
			(play.getY() - playTake.getY() <= 87) &&
			(play.getY() - playTake.getY() >= 2)){
			if (Man < 14 &&
				(playTake.getX() >= 195) &&
				(playTake.getX() <= 309) &&
				(playTake.getY() <= 170) &&
				(playTake.isVisible())){
				Chap = true;
			}
			else if (Man > 13 &&
				(playTake.getX() >= 195) &&
				(playTake.getX() <= 309) &&
				(playTake.getY() >= 455) &&
				playTake.isVisible()){
				Chap = true;
			}
		}
		// down left
		else if ((play.getX() - playTake.getX() <= 114) &&
			(play.getX() - playTake.getX() >= 25) &&
			(play.getY() - playTake.getY() <= -2) &&
			(play.getY() - playTake.getY() >= -87)){
			if (Man < 14 &&
				(playTake.getX() >= 195) &&
				(playTake.getX() <= 309) &&
				(playTake.getY() <= 170) &&
				(playTake.isVisible())){
				Chap = true;
			}
			else if (Man > 13 &&
				(playTake.getX() >= 195) &&
				(playTake.getX() <= 309) &&
				(playTake.getY() >= 455) &&
				playTake.isVisible()){
				Chap = true;
			}
		}
		// down right
		else if ((play.getX() - playTake.getX() <= -25) &&
			(play.getX() - playTake.getX() >= -114) &&
			(play.getY() - playTake.getY() <= -2) &&
			(play.getY() - playTake.getY() >= -87)){
			if (Man < 14 &&
				(playTake.getX() >= 195) &&
				(playTake.getX() <= 309) &&
				(playTake.getY() <= 170) &&
				(playTake.isVisible())){
				Chap = true;
			}
			else if (Man > 13 &&
				(playTake.getX() >= 195) &&
				(playTake.getX() <= 309) &&
				(playTake.getY() >= 455) &&
				playTake.isVisible()){
				Chap = true;
			}
		}
		// 可移动、不能吃自己的棋子
		if (Chap && playTake.getName().charAt(1) != play.getName().charAt(1)){
			Var.add(String.valueOf(play.isVisible()));
			Var.add(String.valueOf(play.getX()));
			Var.add(String.valueOf(play.getY()));
			Var.add(String.valueOf(Man));
			
			Var.add(String.valueOf(playTake.isVisible()));
			Var.add(String.valueOf(playTake.getX()));
			Var.add(String.valueOf(playTake.getY()));
			Var.add(String.valueOf(i));
			
			playTake.setVisible(false);
			play.setBounds(playTake.getX(), playTake.getY(), 55, 55);
		}
	}
	
	// 将的移动规则
	public void willRule(int Man, JLabel play, JLabel playA[], MouseEvent mevent){
		// up
		if (play.getX() - mevent.getX() <= 0 &&
			(play.getX() - mevent.getX() >= -55) &&
			(play.getY() - mevent.getY() <= 87) &&
			(play.getY() - mevent.getY() >= 2)){
			// 将是否超出自己的界限
			if (Man == 30 &&
				(mevent.getX() <= 359) &&
				(mevent.getX() >= 195) &&
				(mevent.getY() <= 170)){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));

				play.setBounds(play.getX(), play.getY() - 57, 55, 55);
			}
			else if (Man == 31 &&
				(mevent.getX() <= 359) &&
				(mevent.getX() >= 195) &&
				(mevent.getY() >= 455)){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				
				play.setBounds(play.getX(), play.getY() - 57, 55, 55);
			}
		}
		// left
		if (play.getX() - mevent.getX() <= 57 &&
			(play.getX() - mevent.getX() >= 2) &&
			(play.getY() - mevent.getY() <= 27) &&
			(play.getY() - mevent.getY() >= -27)){
			// 将是否超出自己的界限
			if (Man == 30 &&
				(mevent.getX() <= 359) &&
				(mevent.getX() >= 195) &&
				(mevent.getY() <= 170)){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));

				play.setBounds(play.getX() - 57, play.getY(), 55, 55);
			}
			else if (Man == 31 &&
				(mevent.getX() <= 359) &&
				(mevent.getX() >= 195) &&
				(mevent.getY() >= 455)){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				
				play.setBounds(play.getX() - 57, play.getY(), 55, 55);
			}
		}
		// right
		if (play.getX() - mevent.getX() <= -57 &&
			(play.getX() - mevent.getX() >= -112) &&
			(play.getY() - mevent.getY() <= 27) &&
			(play.getY() - mevent.getY() >= -27)){
			// 将是否超出自己的界限
			if (Man == 30 &&
				(mevent.getX() <= 359) &&
				(mevent.getX() >= 195) &&
				(mevent.getY() <= 170)){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));

				play.setBounds(play.getX() + 57, play.getY(), 55, 55);
			}
			else if (Man == 31 &&
				(mevent.getX() <= 359) &&
				(mevent.getX() >= 195) &&
				(mevent.getY() >= 455)){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				
				play.setBounds(play.getX() + 57, play.getY(), 55, 55);
			}
		}
		// down
		if (play.getX() - mevent.getX() <= 0 &&
			(play.getX() - mevent.getX() >= -55) &&
			(play.getY() - mevent.getY() <= -27) &&
			(play.getY() - mevent.getY() >= -87)){
			// 将是否超出自己的界限
			if (Man == 30 &&
				(mevent.getX() <= 359) &&
				(mevent.getX() >= 195) &&
				(mevent.getY() <= 170)){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));

				play.setBounds(play.getX(), play.getY() + 57, 55, 55);
			}
			else if (Man == 31 &&
				(mevent.getX() <= 359) &&
				(mevent.getX() >= 195) &&
				(mevent.getY() >= 455)){
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				
				play.setBounds(play.getX(), play.getY() + 57, 55, 55);
			}
		}
	}
	
	// 将帅吃子规则
	public void willRule(int Man, JLabel play, JLabel playTake, JLabel playA[]){
		boolean will = false;
		// 向上吃
		if ((play.getX() - playTake.getX() <= 55) &&
			(play.getX() - playTake.getX() >= 0 ) &&
			(play.getY() - playTake.getY() <= 87) &&
			(play.getY() - playTake.getY() >= 27) &&
			playTake.isVisible()){
			if (Man == 30 && 
				(playTake.getX() <= 309) &&
				(playTake.getX() >= 195) &&
				(playTake.getY() <= 170)){
				will = true;
			}
			else if (Man == 31 && 
				(playTake.getX() <= 309) &&
				(playTake.getX() >= 195) &&
				(playTake.getY() >= 455)){
				will = true;
			}
		}
		// 向左吃
		else if ((play.getX() - playTake.getX() <= 57) &&
			(play.getX() - playTake.getX() >= 2 ) &&
			(play.getY() - playTake.getY() <= 27) &&
			(play.getY() - playTake.getY() >= -27) &&
			playTake.isVisible()){
			if (Man == 30 && 
				(playTake.getX() <= 309) &&
				(playTake.getX() >= 195) &&
				(playTake.getY() <= 170)){
				will = true;
			}
			else if (Man == 31 && 
				(playTake.getX() <= 309) &&
				(playTake.getX() >= 195) &&
				(playTake.getY() >= 455)){
				will = true;
			}
		}
		// 向右吃
		else if ((play.getX() - playTake.getX() <= -2) &&
			(play.getX() - playTake.getX() >= -57 ) &&
			(play.getY() - playTake.getY() <= 27) &&
			(play.getY() - playTake.getY() >= -27) &&
			playTake.isVisible()){
			if (Man == 30 && 
				(playTake.getX() <= 309) &&
				(playTake.getX() >= 195) &&
				(playTake.getY() <= 170)){
				will = true;
			}
			else if (Man == 31 && 
				(playTake.getX() <= 309) &&
				(playTake.getX() >= 195) &&
				(playTake.getY() >= 455)){
				will = true;
			}
		}
		// 向下吃
		else if ((play.getX() - playTake.getX() <= 0) &&
			(play.getX() - playTake.getX() >= -87) &&
			(play.getY() - playTake.getY() <= -40) &&
			(play.getY() - playTake.getY() >= -27) &&
			playTake.isVisible()){
			if (Man == 30 && 
				(playTake.getX() <= 309) &&
				(playTake.getX() >= 195) &&
				(playTake.getY() <= 170)){
				will = true;
			}
			else if (Man == 31 && 
				(playTake.getX() <= 309) &&
				(playTake.getX() >= 195) &&
				(playTake.getY() >= 455)){
				will = true;
			}
		}
		if (playTake.getName().charAt(1) != play.getName().charAt(1) && will){
			Var.add(String.valueOf(play.isVisible()));
			Var.add(String.valueOf(play.getX()));
			Var.add(String.valueOf(play.getY()));
			Var.add(String.valueOf(Man));
			
			Var.add(String.valueOf(playTake.isVisible()));
			Var.add(String.valueOf(playTake.getX()));
			Var.add(String.valueOf(playTake.getY()));
			Var.add(String.valueOf(i));
			
			playTake.setVisible(false);
			play.setBounds(playTake.getX(), playTake.getY(), 55, 55);
		}
	}
	
	// 兵的移动规则
	public void armsRule(int Man, JLabel play, MouseEvent mevent){
		if (Man < 21){	// 黑卒向下
			// 向下移动
			if ((mevent.getY() - play.getY()) > 27 &&
				(mevent.getY() - play.geyY()) < 86 &&
				(mevent.getX() - play.getX()) < 55 &&
				(mevent.getX() - play.getX()) > 0){
				// 当前记录添加到集合，用于悔棋
				Var.add(String.valueOf(play.isVisible()));
				Var.add(String.valueOf(play.getX()));
				Var.add(String.valueOf(play.getY()));
				Var.add(String.valueOf(Man));
				play.setBounds(play.getX(), play.getY() + 57, 55, 55);
			}
			// 向右移动，必须过河
			else if (play.getY() > 284 &&
				(mevent.getX() - play.getX()) >= 57 &&
				(mevent.getX() - play.getX()) <= 112){
				play.setBounds(play.getX() + 57, play.geyY(), 55, 55);
			}
			// 向左移动，必须过河
			else if (play.getY() > 284 &&
				(play.getX() - mevent.getX()) >= 2 &&
				(play.getX() - mevent.getX()) <= 58){
				// 模糊坐标
				play.setBounds(play.getX() - 57, play.getY(), 55, 55);
			}
		}
		else{	// 红兵向上
			// 当前记录添加到集合，用于悔棋
			Var.add(String.valueOf(play.isVisible()));
			Var.add(String.valueOf(play.getX()));
			Var.add(String.valueOf(play.getY()));
			Var.add(String.valueOf(Man));
			play.setBounds(play.getX(), play.getY() + 57, 55, 55);
			// 向上移动
			if ((mevent.getX() - play.getX()) >= 0 &&
				(mevent.getX() - play.getX()) <= 55 &&
				(play.getY() - mevent.getY()) > 27 &&
				(play.getY() - mevent.getY()) < 86){
				play.setBounds(play.getX(), play.getY() - 57, 55, 55);
			}
			// 向右移动，必须过河
			else if (play.getY() <= 341 &&
				(mevent.getX() - play.getX()) >= 57 &&
				(mevent.getX() - play.getX()) <= 112){
				play.setBounds(play.getX() + 57, play.geyY(), 55, 55);
			}
			// 向左移动，必须过河
			else if (play.getY() <= 341 &&
				(play.getX() - mevent.getX()) >= 3 &&
				(play.getX() - mevent.getX()) <= 58){
				// 模糊坐标
				play.setBounds(play.getX() - 57, play.getY(), 55, 55);
			}
		}
	}
	
	// 卒吃棋规则
	public void armsRule(JLabel play1, JLabel play2){
		// 向右
		if ((play2.getX() - play1.getX()) <= 112 &&
			(play2.getX() - play1.getX()) >= 57 &&
			(play1.getY() - play2.getY()) < 22 &&
			(play1.getY() - play2.getY()) > -22 &&
			play2.isVisible() &&
			play1.getName().charAt(1) != play2.getName().charAt(1)){
			// 黑卒过河才能右移吃子
			if (play1.getName().charAt(1) == '1' &&
				play1.getY() > 284 && 
				play1.getName().charAt(1) != play2.getName().charAt(1)){
				play2.setVisible(false);
				// 把对方的位置给自己
				play1.setBounds(play2.getX(), play2.getY(), 55, 55);
			}
			// 红兵过河才能右移吃子
			else if (play1.getName().charAt(1) == '2' &&
				play1.getY() < 341 && 
				play1.getName().charAt(1) != play2.getName().charAt(1)){
				play2.setVisible(false);
				play1.setBounds(play2.getX(), play2.getY(), 55, 55);
			}
		}
		// 向左
		else if ((play1.getX() - play2.getX()) <= 112 &&
			(play1.getX() - play2.getX()) >= 57 &&
			(play1.getY() - play2.getY()) < 22 && 
			(play1.getY() - play2.getY()) > -22 &&
			play2.isVisible() &&
			play1.getName().charAt(1) != play2.getName().charAt(1)){
			if (play1.getName().charAt(1) == '1' &&
				play1.getY() > 284 &&
				play1.getName().charAt(1) != play2.getName().charAt(1)){
				play2.setVisible(false);
				play1.setBounds(play2.getX(), play2.getY(), 55, 55);
			}
			else if (play1.getName().charAt(1) == '2' && 
				play1.getY() < 341 &&
				play1.getName().charAt(1) != play2.getName().charAt(1)){
				play2.setVisible(false);
				play1.setBounds(play2.getX(), play2.getY(), 55, 55);
			}
		}
		// 向上走
		else if (play1.getX() - play2.getX() >= -22 &&
			play1.getX() - play2.getX() <= 22 &&
			play1.getY() - play2.getY() >= -112 &&
			play1.getY() - play2.getY() <= 112){
			// 黑卒不能向上吃子
			if (play1.getName().charAt(1) == '1' &&
				play1.getY() < play2.getY() &&
				play1.getName().charAt(1) != play2.getName().charAt(1)){
				play2.setVisible(false);
				play1.setBounds(play2.getX(), play2.getY(), 55, 55);
			}
			// 红兵不能向下吃子
			else if (play1.getName().charAt(1) == '2' &&
				play1.getY() > play2.getY() &&
				play1.getName().charAt(1) != play2.getName().charAt(1)){
				play2.setVisible(false);
				play1.setBounds(play2.getX(), play2.getY(), 55, 55);
			}
		}
		// 当前记录添加到集合用于悔棋
		Var.add(String.valueOf(play1.isVisible()));
		Var.add(String.valueOf(play1.getX()));
		Var.add(String.valueOf(play1.getY()));
		Var.add(String.valueOf(Man));
		// 当前记录添加到集合用于悔棋
		Var.add(String.valueOf(play2.isVisible()));
		Var.add(String.valueOf(play2.getX()));
		Var.add(String.valueOf(play2.getY()));
		Var.add(String.valueOf(i));
	}// 卒吃结束
}
