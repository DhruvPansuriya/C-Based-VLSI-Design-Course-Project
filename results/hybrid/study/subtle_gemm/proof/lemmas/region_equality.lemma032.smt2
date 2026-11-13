; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x334551 (bvmul arg0_8 arg1_8)))
(let ((?x327942 (bvmul (_ bv4294967295 32) ?x334551)))
(let ((?x306680 (bvmul arg0_8 arg1_2)))
(let ((?x316517 (bvadd ?x306680 ?x327942)))
(and (distinct ?x316517 (_ bv0 32)) true))))))
(check-sat)
