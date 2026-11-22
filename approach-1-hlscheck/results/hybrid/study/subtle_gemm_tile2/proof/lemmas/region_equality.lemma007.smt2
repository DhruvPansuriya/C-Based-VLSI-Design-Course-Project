; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x705235 (bvmul arg0_2 arg1_10)))
(let ((?x182773 (bvmul (_ bv4294967295 32) ?x705235)))
(let ((?x380121 (bvmul arg0_2 arg1_11)))
(let ((?x503501 (bvadd ?x380121 ?x182773)))
(and (distinct ?x503501 (_ bv0 32)) true))))))
(check-sat)
