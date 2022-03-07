public class ObfusString {

    public boolean check() {
        return Rot13.genRot13("EPCGGB") == "A" && Rot13.genRot13("RUYB") == "B" &&
                Rot13.genRot13("ZNVYSEBZ") == "C" && Rot13.genRot13("QNGN") == "D";
    }

    public String genStringObs(int input) {
        boolean a1 = true, a2 = true, b1 = true, b2 = false;
        int c1 = 0, c2 = 0;
        if (input == 0) {
            a1 = false; a2 = false; b1 = false;  b2 = false;
        } else if (input == 1) {
            c1 = 0; c2 = 1;
        } else if (input == 2) {
            a1 = true; a2 = false; c1 = 1; c2 = 1;
        } else if (input == 3) {
            b1 = false; b2 = false; c1 = 1; c2 = 1;
        } else {
            return null;
        }
        int c = 2 * c1 + c2;
        if (c1 == 1) {
            return Rot13.genRot13("EPCGGB");
        } else if (c == 2) {
            if (input * (input -1) % 2 == 0)
                return Rot13.genRot13("EPCGGB");
            else
                return Rot13.genRot13("RUYB");
        } else {
            if (b1 && b2 || (!b1 && !b2)) {
                return Rot13.genRot13("ZNVYSEBZ");
            } else {
                boolean t1 = (b1 && b2) || (!b1 && !b2);
                boolean u1 = (a1 && a2) || (!a1 && !a2);
                if (u1 = t1)
                    return Rot13.genRot13("RUYB");
                else
                    return Rot13.genRot13("QNGN");
            }
        }
    }
}