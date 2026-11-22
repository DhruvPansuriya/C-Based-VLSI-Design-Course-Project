; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x4075 (bvmul arg0_5 arg0_7)))
(let ((?x29543 (bvmul (_ bv4294967295 32) ?x4075)))
(let ((?x791 (bvmul arg0_13 arg0_5)))
(let ((?x25212 (bvadd ?x791 ?x29543)))
(and (distinct ?x25212 (_ bv0 32)) true))))))
(check-sat)
