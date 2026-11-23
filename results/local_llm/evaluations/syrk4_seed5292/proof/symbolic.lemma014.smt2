; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x4066 (bvmul arg0_4 arg0_5)))
(let ((?x25493 (bvmul (_ bv4294967295 32) ?x4066)))
(let ((?x5 (bvmul arg0_1 arg0_5)))
(let ((?x26438 (bvadd ?x5 ?x25493)))
(and (distinct ?x26438 (_ bv0 32)) true))))))
(check-sat)
