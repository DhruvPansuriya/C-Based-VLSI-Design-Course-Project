; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x1621 (bvmul arg0_8 arg2_2)))
(let ((?x11541 (bvmul (_ bv4294967295 32) ?x1621)))
(let ((?x2772 (bvmul arg0_8 arg2_1)))
(let ((?x716814 (bvadd ?x2772 ?x11541)))
(and (distinct ?x716814 (_ bv0 32)) true))))))
(check-sat)
