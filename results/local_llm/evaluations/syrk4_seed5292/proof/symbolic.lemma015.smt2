; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x1331 (bvmul arg0_6 arg0_8)))
(let ((?x33009 (bvmul (_ bv4294967295 32) ?x1331)))
(let ((?x736 (bvmul arg0_2 arg0_6)))
(let ((?x30213 (bvadd ?x736 ?x33009)))
(and (distinct ?x30213 (_ bv0 32)) true))))))
(check-sat)
