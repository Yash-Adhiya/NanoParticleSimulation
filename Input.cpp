#include <iostream>
#include <vector>
#include <cmath>

struct Atom {
    int id;
    int groupID;
    double x, y, z;
};

struct Bond {
    int atom1, atom2;
};

class Molecule {
private:
    std::vector<Atom> atoms;
    std::vector<Bond> bonds;

public:
    void addAtom(int id, int groupID) {
        Atom atom;
        atom.id = id;
        atom.groupID = groupID;
        atom.x = atom.y = atom.z = 0.0;
        atoms.push_back(atom);
    }

    void addBond(int atom1, int atom2) {
        Bond bond;
        bond.atom1 = atom1;
        bond.atom2 = atom2;
        bonds.push_back(bond);
    }

    void generateCoordinates(double bondLength, double angle) {
        // Convert angle to radians
        double angleRad = angle * M_PI / 180.0;

        // Calculate the coordinates of the atoms based on bond angles
        atoms[0].x = 0.0;
        atoms[0].y = 0.0;
        atoms[0].z = 0.0;

        atoms[1].x = bondLength;
        atoms[1].y = 0.0;
        atoms[1].z = 0.0;

        atoms[2].x = bondLength * std::cos(angleRad);
        atoms[2].y = bondLength * std::sin(angleRad);
        atoms[2].z = 0.0;
    }

    void displayConfiguration() {
        std::cout << "\nMolecule Configuration:\n";
        for (const auto &bond : bonds) {
            std::cout << "   " << atoms[bond.atom1 - 1].groupID << "----" << atoms[bond.atom2 - 1].groupID << "\n";
        }

        std::cout << "\nAtom Coordinates:\n";
        for (const auto &atom : atoms) {
            std::cout << "Atom " << atom.id << " (Group " << atom.groupID << "): "
                      << "(X, Y, Z) = (" << atom.x << ", " << atom.y << ", " << atom.z << ")\n";
        }
    }
};

int main() {
    Molecule molecule;

    int numAtoms, numBonds;
    std::cout << "Enter the number of atoms: ";
    std::cin >> numAtoms;

    for (int i = 1; i <= numAtoms; ++i) {
        int groupID;
        std::cout << "Enter the group ID for atom " << i << ": ";
        std::cin >> groupID;
        molecule.addAtom(i, groupID);
    }

    std::cout << "Enter the number of bonds: ";
    std::cin >> numBonds;

    for (int i = 0; i < numBonds; ++i) {
        int atom1, atom2;
        std::cout << "Enter the atom indices connected by bond " << i + 1 << ": ";
        std::cin >> atom1 >> atom2;
        molecule.addBond(atom1, atom2);
    }

    double bondLength, bondAngle;
    std::cout << "Enter the bond length: ";
    std::cin >> bondLength;

    std::cout << "Enter the bond angle in degrees: ";
    std::cin >> bondAngle;

    molecule.generateCoordinates(bondLength, bondAngle);
    molecule.displayConfiguration();

    return 0;
}
