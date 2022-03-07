public class Mul {

    int multiply450bs(int y) {
        boolean a = true;
        boolean b = false;
        int z = 1;
        boolean c = false;
        while (true) {
            if (!a) {
                if (!b) {
                    y = z + y;
                    a = !a;
                    b = !b;
                    c = !c;
                    if (!c)
                        break;
                } else {
                    z = z + y;
                    a = !a;
                    b = !b;
                    c = !c;
                    if (!c) break;
                }
            } else {
                if (!b) {
                    z = y << 2;
                    a = !a;
                } else {
                    z = y << 3;
                    a = !a;
                    b = !b;
                }
            }
        }
        return y;
    }

    int multiply450bs2(int y) {
        boolean a = true;
        boolean b = false;
        int z = 1;
        boolean c = false;
        if (!a) {
            if (!b) {
                y = z + y;
                a = !a;
                b = !b;
                c = !c;
                if (!c) {
                    y = z;
                    return y;
                }
            } else {
                z = z + y;
                a = !a;
                b = !b;
                c = !c;
                if (!c) {
                    y = z;
                    return y;
                }
            }
        } else {
            if (b) {
                z = y << 2;
                a = !a;
            } else {
                z = y << 3;
                a = !a;
                b = !b;
            }
        }
        y = z;
        return y;
    }
}