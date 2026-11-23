; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let (($x722515 (and (distinct (_ bv0 32) (_ bv0 32)) true)))
(let ((?x723671 (bvmul (_ bv4294967293 32) arg0_6)))
(let ((?x728852 (bvmul (_ bv3 32) arg0_7)))
(let ((?x717566 (bvadd ?x728852 ?x723671)))
(let (($x802 (and (distinct (_ bv0 32) ?x717566) true)))
(let (($x21110 (and true true (or $x802 $x722515 $x722515 $x722515 $x722515 $x722515 $x722515 $x722515 $x722515))))
(or $x21110))))))))
(check-sat)
