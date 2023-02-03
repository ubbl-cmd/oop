#ifndef DIAGONALWALLRULE
#define DIAGONALWALLRULE

template<int a, int b, bool direction>
class DiagonalWallRule {
public:
	virtual void fill(Field * field, Player &player, GameStatus &gameStatus) {
		int hdiff, wdiff;
		if (direction) {
			hdiff = 1;
			wdiff = -1;
		} else {
			hdiff = 1;
			wdiff = 1;
		}
		if (a < field->getWidth() && b < field->getHeight()) {
			int h = b;
			int w = a;
			while(h >= 0 && w >= 0 && h < field->getHeight() && w < field->getWidth()) {
				if (!field->getCell(h,w).getEvent())
					field->getCell(h,w).setPassable(0);
				w += wdiff;
				h += hdiff;
			}
			h = b;
			w = a;
			while(h >= 0 && w >= 0 && h < field->getHeight() && w < field->getWidth()) {
				if (!field->getCell(h,w).getEvent())
					field->getCell(h,w).setPassable(0);
				w-=wdiff;
				h-=hdiff;
			}
		}
	}
};

#endif
