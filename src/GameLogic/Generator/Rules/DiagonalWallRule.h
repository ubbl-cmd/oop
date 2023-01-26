#ifndef DIAGONALWALLRULE
#define DIAGONALWALLRULE

template<int a>
class DiagonalWallRule {
public:
	virtual void fill(Field * field, Player &player, GameStatus &gameStatus) {
		if (a < field->getWidth() && a < field->getHeight()) {
			int h = a;
			int w = a;
			while(h >= 0 && w < field->getWidth()) {
				if (!field->getCell(h,w).getEvent())
					field->getCell(h,w).setPassable(0);
				w++;
				h--;
			}
			h = a;
			w = a;
			while(w >= 0 && h < field->getHeight()) {
				if (!field->getCell(h,w).getEvent())
					field->getCell(h,w).setPassable(0);
				w--;
				h++;
			}
		}
	}
};

#endif
