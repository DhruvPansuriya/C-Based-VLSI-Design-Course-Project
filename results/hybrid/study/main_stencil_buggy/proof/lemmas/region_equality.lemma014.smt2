; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_17 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x5033 (bvmul arg0_17 arg2_8)))
(let ((?x138 (bvmul (_ bv4294967295 32) ?x5033)))
(let ((?x1647 (bvmul arg0_17 arg2_7)))
(let ((?x726298 (bvadd ?x1647 ?x138)))
(and (distinct ?x726298 (_ bv0 32)) true))))))
(check-sat)
