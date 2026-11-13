; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x334667 (bvmul arg0_10 arg1_6)))
(let ((?x314232 (bvmul (_ bv4294967295 32) ?x334667)))
(let ((?x293617 (bvmul arg0_10 arg1_9)))
(let ((?x90944 (bvadd ?x293617 ?x314232)))
(and (distinct ?x90944 (_ bv0 32)) true))))))
(check-sat)
