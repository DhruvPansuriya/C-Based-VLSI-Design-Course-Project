; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_3 () (_ BitVec 32))
(declare-fun arg0_18 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x16864 (bvmul arg0_18 arg2_3)))
(let ((?x727977 (bvmul (_ bv4294967295 32) ?x16864)))
(let ((?x19256 (bvmul arg0_18 arg2_4)))
(let ((?x714228 (bvadd ?x19256 ?x727977)))
(and (distinct ?x714228 (_ bv0 32)) true))))))
(check-sat)
