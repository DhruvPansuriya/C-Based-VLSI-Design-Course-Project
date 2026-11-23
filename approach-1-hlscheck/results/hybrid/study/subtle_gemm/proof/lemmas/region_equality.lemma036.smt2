; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x334656 (bvmul arg0_9 arg1_13)))
(let ((?x326106 (bvmul (_ bv4294967295 32) ?x334656)))
(let ((?x340424 (bvmul arg0_9 arg1_7)))
(let ((?x90944 (bvadd ?x340424 ?x326106)))
(and (distinct ?x90944 (_ bv0 32)) true))))))
(check-sat)
